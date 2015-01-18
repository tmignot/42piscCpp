#include "Hostname.hpp"
#include <iostream>

Hostname::Hostname(void) : IMonitorModule(), type('i'), data(std::vector<std::string>()), name("Hostname")
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

Hostname::Hostname(Hostname const &hostname) : IMonitorModule() {*this = hostname;}
Hostname::~Hostname(void) {}
Hostname								&Hostname::operator=(Hostname const&) {return (*this);}

std::vector<std::string> const			&Hostname::getData(void) const { return (this->data); }

char									Hostname::getType(void) const
{
	return (this->type);
}

std::string const						&Hostname::getName(void) const
{
	return (this->name);
}
