#include "RAM.hpp"

RAM::RAM(void) : IMonitorModule(), type('i'), data(std::vector<std::string>()), name("RAM")
{
	this->update();
}
RAM::RAM(RAM const &ram) : IMonitorModule() {*this = ram;}
RAM::~RAM(void) {}
RAM								&RAM::operator=(RAM const&) {return (*this);}
std::vector<std::string> const	&RAM::getData() const
{
	return (this->data);
}

void							RAM::update(void)
{
	struct xsw_usage swap;
	size_t bufSize = 0;

	data.clear();
	int mib[2];
	int64_t physical_memory;
	mib[0] = CTL_HW;
	mib[1] = HW_MEMSIZE;
	size_t length = sizeof(int64_t);
	sysctl(mib, 2, &physical_memory, &length, NULL, 0);
	vm_size_t page_size;
	mach_port_t mach_port;
	mach_msg_type_number_t count;
	vm_statistics64_data_t vm_stats;

	mach_port = mach_host_self();
	count = sizeof(vm_stats) / sizeof(natural_t);
	long long free_memory, used_memory;
	host_page_size(mach_port, &page_size);
	host_statistics64(mach_port, HOST_VM_INFO, 
			reinterpret_cast<host_info64_t>(&vm_stats), &count);
	free_memory = (int64_t)vm_stats.free_count * (int64_t)page_size;
	used_memory = ((int64_t)vm_stats.active_count +
				(int64_t)vm_stats.inactive_count +
				(int64_t)vm_stats.wire_count) *  (int64_t)page_size;
	free_memory /= (1024*1024);
	used_memory /= (1024*1024);
	physical_memory /= (1024*1024);

	mib[0] = CTL_VM;
	mib[1] = VM_SWAPUSAGE;
	sysctl(mib, 2, NULL, &bufSize, NULL, 0);
	sysctl(mib, 2, &swap, &bufSize, NULL, 0);
	unsigned int totalSwap = swap.xsu_total / (1024 * 1024);
	unsigned int usedSwap = swap.xsu_used / (1024 * 1024);
	std::ostringstream sstr;
	data.push_back("  RAM usage  ");
	sstr << " used: "<< used_memory << "Mo";
	data.push_back(sstr.str());
	sstr.str("");
	sstr << " free: "<< free_memory << "Mo";
	data.push_back(sstr.str());
	sstr.str("");
	sstr << "total: " << physical_memory << "Mo";
	data.push_back(sstr.str());
	sstr.str("");
	sstr << "Swap: " << usedSwap << "/" << totalSwap << "Mo";
	data.push_back(sstr.str());
}

char							RAM::getType(void) const
{
	return (this->type);
}

std::string const				&RAM::getName(void) const
{
	return (this->name);
}
