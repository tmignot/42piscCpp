#include "GKrellM.hpp"

int		main(int ac, char **av)
{
	IMonitorDisplay		*monitor = NULL;
	Options				options(ac, av);
	
	if (options.shell())
	{
		Hostname		host;
		monitor = new ShellDisplay();
		monitor->addModule(host);
		Hostname		second;
		monitor->addModule(second);
		while (getch() != ' ')
		{
			monitor->draw();
			usleep(100000);
		}
	}
	else if (options.windowed())
		monitor = new WindowedDisplay();
	else
		options.printErrors();
	if (monitor)
		delete monitor;
	return (0);
}
