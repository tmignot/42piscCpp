#include "Hostname.hpp"
#include <iostream>

Hostname::Hostname(void) : IMonitorModule(), type('i'), data(std::vector<std::string>())
{
	this->update();
}

void									Hostname::update(void)
{
	this->data.clear();
	std::string		hostName;
	std::string		userName;
	{
		char host[32];
		size_t size = sizeof(host);

		sysctlbyname("kern.hostname", &host, &size, NULL, 0);
		hostName.assign(std::string(host));
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
		userName.assign(user);
	}		
	this->data.push_back(userName);
	this->data.push_back(hostName);
}

int								Hostname::getWidth(void) const
{
	int			ret = 0;

	for (std::vector<std::string>::const_iterator it = this->data.begin(); it != this->data.end(); ++it)
	{
		if ((*it).length() > static_cast<unsigned int>(ret))
			ret = (*it).length();
	}
	return (ret);
}

Hostname::Hostname(Hostname const &hostname) : IMonitorModule() {*this = hostname;}
Hostname::~Hostname(void) {}
Hostname								&Hostname::operator=(Hostname const&) {return (*this);}

std::vector<std::string> const			&Hostname::getData(void) const { return (this->data); }
WINDOW									*Hostname::initWindow(WINDOW *lastwin, WINDOW *displaywin) const
{
	int					w = this->getWidth();
	WINDOW				*local_win = NULL;
	if (lastwin)
	{
		if (getbegy(lastwin) + getmaxy(lastwin) + 4 < getmaxy(displaywin))
		{
			if (getbegx(lastwin) + 1 + w < getmaxx(displaywin))
				local_win = newwin(4, w, getbegy(lastwin) + getmaxy(lastwin) + 1, getbegx(lastwin));
		}
		else
		{
			if (getbegx(lastwin) + getmaxx(lastwin) + 1 + w < getmaxx(displaywin))
				local_win = newwin(4, w, 1, getbegx(lastwin) + getmaxx(lastwin) + 1);
		}
	}
	else
		local_win = newwin(4, w, 1, 1);
	if (local_win)
	{
		box(local_win, 0, 0);
		wrefresh(local_win);
	}
	return (local_win);
}

char									Hostname::getType(void) const
{
	return (this->type);
}
