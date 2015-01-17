#ifndef RAM_HPP
# define RAM_HPP

#include <iostream>
#include <unistd.h>
#include <sys/sysctl.h>
#include <mach/mach.h>
#include <mach/host_info.h>
#include <mach/vm_statistics.h>
#include "IMonitorModule.hpp"

class RAM : public IMonitorModule
{
	private:
		char										type;
		std::vector<std::string>					data;
		int											getWidth(void) const;
	protected:
	public:
		RAM(void);
		RAM(RAM const&);
		~RAM(void);
		RAM											&operator=(RAM const&);
		virtual void								update(void) const;
		virtual std::vector<std::string> const		&getData(void) const;
		virtual char								getType(void) const;
		virtual WINDOW								*initWindow(WINDOW*, WINDOW*) const; 
};

#endif
