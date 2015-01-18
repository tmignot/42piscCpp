#ifndef OS_HPP
# define OS_HPP

#include "IMonitorModule.hpp"
#include <sys/sysctl.h>

class OS : public IMonitorModule
{
	private:
		char										type;
		std::vector<std::string>					data;
		int											getWidth(void) const;
		std::string									name;
	protected:
	public:
		OS(void);
		OS(OS const&);
		~OS(void);
		OS											&operator=(OS const&);
		virtual void								update(void);
		virtual std::vector<std::string> const		&getData(void) const;
		virtual char								getType(void) const;
		virtual WINDOW								*initWindow(WINDOW*, WINDOW*) const;
		virtual std::string const					&getName(void) const;
};

#endif
