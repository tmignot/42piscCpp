#include "RAM.hpp"

template<typename T>
std::string to_string(T num) {
	std::stringstream sstm;
	sstm << num;

	return (sstm.str());
}

RAM::RAM(void) : IMonitorModule(), type('i'), data(std::vector<std::string>())
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

void							RAM::update(void) const
{
	vm_statistics_data_t 		vm;
	mach_msg_type_number_t ic = HOST_VM_INFO_COUNT;
	uint64_t pagesize = getpagesize();
	struct xsw_usage s; 
  	size_t len = sizeof(s);
  	size_t len2 = sizeof(uint64_t);

	host_statistics( mach_host_self(), HOST_VM_INFO, (host_info_t) &vm, &ic );

	this->data.clear();

	uint64_t total_ram;
	if (sysctlbyname( "hw.memsize", &toto, &len2, NULL, 0) == -1)
    	total_ram = 0;

    this->data.push_back(std::string("Ram total\t")
		+ to_string(total_ram));
	this->data.push_back(std::string("Ram avaliable\t")
		+ to_string(pagesize * vm.free_count));
	this->data.push_back(std::string("Ram active\t")
		+ to_string(pagesize * vm.active_count));
	this->data.push_back(std::string("Ram inactive\t")
		+ to_string(pagesize * vm.inactive_count));
	this->data.push_back(std::string("Ram wired\t")
		+ to_string(pagesize * vm.wire_count));

	if ( sysctlbyname( "vm.swapusage", &s, &len, NULL, 0 ) == 0 ) {
	    this->data.push_back(std::string("Swap total\t")
			+ to_string(s.xsu_total));
		this->data.push_back(std::string("Swap avaliable\t")
			+ to_string(s.xsu_avail));
		this->data.push_back(std::string("Swap used\t")
			+ to_string(s.xsu_used));
	 }
}

int								RAM::getWidth(void) const
{
	int			ret = 0;

	for (std::vector<std::string>::const_iterator it = this->data.begin(); it != this->data.end(); ++it)
	{
		if ((*it).length() > ret)
			ret = (*it).length();
	}
	return (ret);
}

WINDOW							*RAM::initWindow(WINDOW *lastwin, WINDOW *displaywin) const
{
	int					w = this->getWidth() + 2;
	int					h = this->data.size() + 2;
	WINDOW				*local_win = NULL;
	if (lastwin)
	{
		if (getbegy(lastwin) + getmaxy(lastwin) + h + 1 < getmaxy(displaywin))
		{
			if (getbegx(lastwin) + 1 + w < getmaxx(displaywin))
				local_win = newwin(h, w, getbegy(lastwin) + getmaxy(lastwin) + 1, getbegx(lastwin));
		}
		else
		{
			if (getbegx(lastwin) + getmaxx(lastwin) + 1 + w < getmaxx(displaywin))
				local_win = newwin(h, w, 1, getbegx(lastwin) + getmaxx(lastwin) + 1);
		}
	}
	else
		local_win = newwin(h, w, 1, 1);
	if (local_win)
	{
		box(local_win, 0, 0);
		wrefresh(local_win);
	}
	return (local_win);
}

char							RAM::getType(void) const
{
	return (this->type);
}
