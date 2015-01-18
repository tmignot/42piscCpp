#ifndef RAM_HPP
# define RAM_HPP

#include "IMonitorModule.hpp"
#include <sys/sysctl.h>
#include <mach/mach.h>
#include <sstream>

class RAM : public IMonitorModule
{
	private:
		char										type;
		std::vector<std::string>					data;
		std::string									name;
		int											getWidth(void) const;
	protected:
	public:
		RAM(void);
		RAM(RAM const&);
		~RAM(void);
		RAM											&operator=(RAM const&);
		virtual void								update(void);
		virtual std::vector<std::string> const		&getData(void) const;
		virtual char								getType(void) const;
		virtual WINDOW								*initWindow(WINDOW*, WINDOW*) const; 
		virtual std::string const					&getName(void) const;
};

#endif
