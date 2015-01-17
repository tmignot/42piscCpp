#include "GKrellM.hpp"

int		main(int ac, char **av)
{
	IMonitorDisplay		*monitor = NULL;
	Options				options(ac, av);
	
	if (options.shell())
	{
		Time		time;
		Hostname	host;
		CPU			cpu;
		OS			os;
		monitor = new ShellDisplay();
		monitor->addModule(time);
		monitor->addModule(host);
		monitor->addModule(cpu);
		monitor->addModule(os);
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
