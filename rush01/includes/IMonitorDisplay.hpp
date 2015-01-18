#ifndef I_MONITOR_DISPLAY_HPP
# define I_MONITOR_DISPLAY_HPP

#include "IMonitorModule.hpp"

class IMonitorDisplay
{
	private:
	protected:
	public:
		IMonitorDisplay(void);
		IMonitorDisplay(IMonitorDisplay const&);
		virtual ~IMonitorDisplay(void);
		IMonitorDisplay				&operator=(IMonitorDisplay const&);
		virtual void				draw(void) const = 0;
		virtual std::string const	&parseCommand(char code) = 0;
};

#endif
