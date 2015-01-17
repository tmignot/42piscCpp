#ifndef HOSTNAME_HPP
# define HOSTNAME_HPP

#include "IMonitorModule.hpp"

class Hostname : public IMonitorModule
{
	private:
	protected:
	public:
		Hostname(void);
		Hostname(Hostname const&);
		~Hostname(void);
		Hostname			&operator=(Hostname const&);
};

#endif
