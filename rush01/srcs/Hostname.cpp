#include "Hostname.hpp"

Hostname::Hostname(void) : IMonitorModule() 
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
	_data[0] = _userName;
	_data[1] = _hostName;
}

Hostname::Hostname(Hostname const &hostname) : IMonitorModule() {*this = hostname;}
Hostname::~Hostname(void) {}
Hostname								&Hostname::operator=(Hostname const&) {return (*this);}

std::vector<std::string> const			&Hostname::getData(void) const { return _data; }
WINDOW									*Hostname::initWindow(WINDOW *lastwin) const
{
	unsigned int		w = (this->_hostName.length() >= this->_userName.length() ? this->_hostName.length() : this->_userName.length()) + 2;
	WINDOW				*local_win;
	local_win = newwin(4, w, getbegy(lastwin), getbegx(lastwin));
	box(local_win, 0 , 0);
	wrefresh(local_win);
	return (local_win);
}
