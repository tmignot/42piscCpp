#ifndef I_MONITOR_DISPLAY_HPP
# define I_MONITOR_DISPLAY_HPP

#include "Module.hpp"

class IMonitorDisplay
{
	private:
	protected:
	public:
		IMonitorDisplay(void);
		IMonitorDisplay(IMonitorDisplay const&);
		virtual ~IMonitorDisplay(void)=0;
		IMonitorDisplay				&operator=(IMonitorDisplay const&);
		virtual void				draw(void)=0;
		virtual void				addModule(Module &)=0;
};

#endif
