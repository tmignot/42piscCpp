#ifndef HOSTNAME_HPP
# define HOSTNAME_HPP

#include "IMonitorModule.hpp"
#include <sys/sysctl.h>
#include <cstring>
#include <string>

class Hostname : public IMonitorModule
{
	private:
		char										type;
		std::vector<std::string>					data;
		int 										getWidth(void) const;
	protected:
	public:
		Hostname(void);
		Hostname(Hostname const&);
		~Hostname(void);
		Hostname									&operator=(Hostname const&);

		virtual std::vector<std::string> const		&getData(void) const;
		virtual WINDOW								*initWindow(WINDOW*, WINDOW*) const;
		virtual char								getType(void) const;
		virtual void								update(void);
};

#endif
