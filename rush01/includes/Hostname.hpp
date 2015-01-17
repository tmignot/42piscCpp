#ifndef HOSTNAME_HPP
# define HOSTNAME_HPP

#include "IMonitorModule.hpp"
#include <sys/sysctl.h>
#include <cstring>
#include <string>

class Hostname : public IMonitorModule
{
	private:
		std::string		_userName;
		std::string		_hostName;

	protected:
	public:
		Hostname(void);
		Hostname(Hostname const&);
		~Hostname(void);
		Hostname			&operator=(Hostname const&);
};

#endif
