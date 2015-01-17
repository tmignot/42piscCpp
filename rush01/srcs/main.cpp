#include "GKrellM.hpp"

int		main(int ac, char **av)
{
	IMonitorDisplay		*monitor = NULL;
	Options				options(ac, av);
	
	if (options.shell())
		monitor = new ShellDisplay();
	else if (options.windowed())
		monitor = new WindowedDisplay();
	else
		options.printErrors();
	if (monitor)
		delete monitor;
	return (0);
}
