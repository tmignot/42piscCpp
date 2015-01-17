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
}

Hostname::Hostname(Hostname const &hostname) : IMonitorModule() {*this = hostname;}
Hostname::~Hostname(void) {}
Hostname				&Hostname::operator=(Hostname const&) {return (*this);}
