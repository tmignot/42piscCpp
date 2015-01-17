#include "Hostname.hpp"
#include <iostream>

Hostname::Hostname(void) : IMonitorModule(), type('i')
{
	{
		char host[32];
		size_t size = sizeof(host);

		sysctlbyname("kern.hostname", &host, &size, NULL, 0);
		_hostName = std::string(host);
	}
	{
		extern char **environ;
		std::string user;

		for (int i = 0; environ[i]; ++i) {
			if (strncmp(environ[i], "USER=", 5) == 0) {
				user = std::string(environ[i]).substr(5);
				break;
			}
		}
		_userName = user;
	}		
	_data.reserve(2);
	_data.push_back(_userName);
	_data.push_back(_hostName);
}

Hostname::Hostname(Hostname const &hostname) : IMonitorModule() {*this = hostname;}
Hostname::~Hostname(void) {}
Hostname								&Hostname::operator=(Hostname const&) {return (*this);}

std::vector<std::string> const			&Hostname::getData(void) const { return _data; }
WINDOW									*Hostname::initWindow(WINDOW *lastwin, WINDOW *displaywin) const
{
	int					w = (this->_hostName.length() >= this->_userName.length() ? this->_hostName.length() : this->_userName.length()) + 2;
	WINDOW				*local_win = NULL;
	if (lastwin)
	{
		if (getmaxy(lastwin) + 3 < getmaxy(displaywin))
		{
			if (getbegx(lastwin) + 1 + w < getmaxx(displaywin))
				local_win = newwin(4, w, getmaxy(lastwin), getbegx(lastwin));
		}
		else
		{
			if (getmaxx(lastwin) + 1 + w < getmaxx(displaywin))
				local_win = newwin(4, w, 1, getmaxx(lastwin) + 1);
		}
	}
	else
		local_win = newwin(4, w, 1, 1);
	if (local_win)
	{
		box(local_win, 0 , 0);
		wrefresh(local_win);
	}
	return (local_win);
}

char									Hostname::getType(void) const
{
	return (this->type);
}
