#include "CPU.hpp"

CPU::CPU(void) : IMonitorModule(), type('i'), data(std::vector<std::string>())
{
	for (unsigned int i = 0; i < 4; ++i) {
		totaltime[i][0] = totaltime[i][1] = 0;
		temp[i] = 0;
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
	data.clear();
	host_processor_info( mach_host_self(), PROCESSOR_CPU_LOAD_INFO,
						&cpu_count,
						reinterpret_cast<processor_info_array_t*>(&cpu_load),		
						&cpu_msg_count);

	unsigned int per_temps_count;
	host_processor_info(mach_host_self(), PROCESSOR_TEMPERATURE,
						&cpu_count, reinterpret_cast<int**>(&temp), &per_temps_count);

	std::ostringstream sstr;

	sstr << "      CPUs: " << cpu_count;
	data.push_back(sstr.str());
	data.push_back("   CPU load:");
	for (unsigned int i = 0; i < cpu_count; ++i) {
		std::ostringstream sstr2;
		totaltime[i][0] = cpu_load[i].cpu_ticks[CPU_STATE_USER] +
						  cpu_load[i].cpu_ticks[CPU_STATE_SYSTEM];
		sstr2 << "   [" << i << "]: " << (totaltime[i][0] - totaltime[i][1]) << "%%  ";
		data.push_back(sstr2.str());
		totaltime[i][1] = totaltime[i][0];
	}
}

int								CPU::getWidth(void) const
{
	int			ret = 0;

	for (std::vector<std::string>::const_iterator it = this->data.begin(); it != this->data.end(); ++it)
	{
		if ((*it).length() > static_cast<unsigned int>(ret))
			ret = (*it).length();
	}
	return (ret);
}

WINDOW							*CPU::initWindow(WINDOW *lastwin, WINDOW *displaywin) const
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

char							CPU::getType(void) const
{
	return (this->type);
}
