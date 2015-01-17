#ifndef HOSTNAME_HPP
# define HOSTNAME_HPP

#include "IMonitorModule.hpp"
#include <sys/sysctl.h>
#include <cstring>
#include <string>

class Hostname : public IMonitorModule
{
	private:
		std::string				_userName;
		std::string				_hostName;
		std::vector<std::string> _data;

	protected:
	public:
		Hostname(void);
		Hostname(Hostname const&);
		~Hostname(void);
		Hostname			&operator=(Hostname const&);

		virtual std::vector<std::string> const& getData() const;
};

#endif
