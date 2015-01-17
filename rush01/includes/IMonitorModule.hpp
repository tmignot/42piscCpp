#ifndef I_MONITOR_MODULE_HPP
# define I_MONITOR_MODULE_HPP

#include <string>
#include <vector>
#include <ncurses.h>

class IMonitorModule
{
	private:
	protected:
	public:
		IMonitorModule(void);
		IMonitorModule(IMonitorModule const&);
		virtual ~IMonitorModule(void);
		IMonitorModule								&operator=(IMonitorModule const&);

		virtual std::vector<std::string> const 		&getDatas(void) const = 0;
		virtual WINDOW								*initWindow(WINDOW*, WINDOW*) const = 0;
};

#endif
