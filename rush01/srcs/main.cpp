#include "GKrellM.hpp"


void		myexit( IMonitorDisplay *mon )
{
	if (mon)
		delete mon;
	exit(0);
}

std::string		keyEvent( IMonitorDisplay *mon ){
	timeout(0);
	int  ch  = getch();
	switch (ch){
		case 'o':
			mon->addModule('o');
			return "haut";
		case ' ':
			myexit( mon );
			return "sp";
		case 27:	// escape
			if (getch() == -1)
				return "escape";
			return "segfault";
		default:
			return "je met ce que je veux!";
	}
}


int		main(int ac, char **av)
{
	IMonitorDisplay		*monitor = NULL;
	Options				options(ac, av);
	
	if (options.shell())
	{
		monitor = new ShellDisplay();
		monitor->addModule('t');
		monitor->addModule('h');
		monitor->addModule('c');
		monitor->addModule('o');
		while ( 1 )
		{
			keyEvent( monitor );
			monitor->draw();
			sleep(1);
		}
	}
	else if (options.windowed())
		monitor = new WindowedDisplay();
	else
		options.printErrors();
	myexit(monitor);
}
