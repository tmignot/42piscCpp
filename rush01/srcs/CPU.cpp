#include "CPU.hpp"

CPU::CPU(void) : IMonitorModule(), type('i'), data(std::vector<std::string>()), name("CPU")
{
	for (unsigned int i = 0; i < 4; ++i) {
		totaltime[i][0] = totaltime[i][1] = 0;
	}
	this->update();
}
CPU::CPU(CPU const &cpu) : IMonitorModule() {*this = cpu;}
CPU::~CPU(void) {}
CPU				&CPU::operator=(CPU const&) {return (*this);}
std::vector<std::string> const	&CPU::getData() const
{
	return (this->data);
}

void							CPU::update(void)
{
	static int j = 0;
	if (!(j % 10)) {
		data.clear();
		host_processor_info( mach_host_self(), PROCESSOR_CPU_LOAD_INFO,
				&cpu_count,
				reinterpret_cast<processor_info_array_t*>(&cpu_load),		
				&cpu_msg_count);

		std::ostringstream sstr;

		char cpu_type[48];
		size_t l = sizeof(cpu_type);
		sysctlbyname("machdep.cpu.brand_string", &cpu_type, &l, NULL, 0);
		data.push_back(cpu_type);
		sstr << "      CPUs: " << cpu_count;
		data.push_back(sstr.str());
		data.push_back("   CPU load:");
		for (unsigned int i = 0; i < cpu_count; ++i) {
			std::ostringstream sstr2;
			totaltime[i][0] = cpu_load[i].cpu_ticks[CPU_STATE_USER] +
							  cpu_load[i].cpu_ticks[CPU_STATE_SYSTEM];
			if (j)
				sstr2 << "   [" << i << "]: " << (totaltime[i][0] - totaltime[i][1]) << "%%  ";
			else
				sstr2 << "   [" << i << "]: " << 0 << "%%    ";
			totaltime[i][1] = totaltime[i][0];
			data.push_back(sstr2.str());
		}
	}
	++j;
}

char							CPU::getType(void) const
{
	return (this->type);
}

std::string const				&CPU::getName(void) const
{
	return (this->name);
}
