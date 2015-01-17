#include "GKrellM.hpp"

int		main(int ac, char **av)
{
	IMonitorDisplay		*monitor = NULL;
	Options				options(ac, av);
	
	if (options.shell())
	{
		CPU		host;
		monitor = new ShellDisplay();
		monitor->addModule(host);
		while (getch() != ' ')
		{
			monitor->draw();
			sleep(1);
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
