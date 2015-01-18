#include "OS.hpp"

OS::OS(void) : IMonitorModule(), type('i'), data(std::vector<std::string>()), name("OS")
{
	this->update();
}
OS::OS(OS const &os) : IMonitorModule() {*this = os;}
OS::~OS(void) {}
OS								&OS::operator=(OS const&) {return (*this);}
char							OS::getType(void) const
{
	return (this->type);
}
std::vector<std::string> const	&OS::getData(void) const
{
	return (this->data);
}
void							OS::update(void)
{
	char os[256];
	char type[256];
	size_t len = sizeof(os);

	data.clear();
	sysctlbyname("kern.ostype", &os, &len, NULL, 0);
	sysctlbyname("kern.osrelease", &type, &len, NULL, 0);
	data.push_back(std::string("OS type: ") + std::string(os));
	data.push_back(std::string("OS Release: ") + std::string(type));
}
WINDOW							*OS::initWindow(WINDOW *lastwin, WINDOW *displaywin) const
{
	int					w = this->getWidth() + 2;
	int					h = this->data.size() + 2;
	WINDOW				*local_win = NULL;
	if (lastwin)
	{
		if (getbegy(lastwin) + getmaxy(lastwin) + h + 1 < getmaxy(displaywin))
		{
			if (getbegx(lastwin) + 1 + w < getmaxx(displaywin))
				local_win = newwin(h, w, getbegy(lastwin) + getmaxy(lastwin), getbegx(lastwin));
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
int								OS::getWidth(void) const
{
	int			ret = 0;

	for (std::vector<std::string>::const_iterator it = this->data.begin(); it != this->data.end(); ++it)
	{
		if ((*it).length() > static_cast<unsigned int>(ret))
			ret = (*it).length();
	}
	return (ret);
}

std::string const						&OS::getName(void) const
{
	return (this->name);
}
