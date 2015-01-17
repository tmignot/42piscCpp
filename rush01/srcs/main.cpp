#include "GKrellM.hpp"

int		main(int ac, char **av)
{
	IMonitorDisplay		*monitor = NULL;
	Options				options(ac, av);
	
	if (options.shell())
	{
		monitor = new ShellDisplay(100, 100, 0, 0);
		Hostname		tamere;
		Module			tonpere(tamere, true, 40, 40, 0, 0);
		monitor->addModule(tonpere);
		while (getch() != ' ')
			monitor->draw();
	}
	else if (options.windowed())
		monitor = new WindowedDisplay();
	else
		options.printErrors();
	if (monitor)
		delete monitor;
	return (0);
}
