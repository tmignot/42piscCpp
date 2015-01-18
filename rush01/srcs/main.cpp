#include "GKrellM.hpp"

void		myexit( IMonitorDisplay *mon )
{
	if (mon)
		delete mon;
}

std::string		keyEvent( IMonitorDisplay *mon, bool &running ){
	timeout(0);
	int  ch;
	while ((ch = getch()) != ERR) {
		switch (ch) {
			case 'h':
			case 'c':
			case 't':
			case 'o':
			case 'r':
			case 'n':
				mon->parseCommand(ch);
				break;
			case ' ':
				myexit( mon );
				running = false;
				return "sp";
			case 27:	// escape
				if (getch() == -1)
					return "escape";
				return "segfault";
			default:
				continue;
		}
	}
	return "je met ce que je veux!";
}

int		main(int ac, char **av)
{
	IMonitorDisplay		*monitor = NULL;
	Options				options(ac, av);
	
	if (options.shell())
	{
		monitor = new ShellDisplay();
		monitor->draw();
		bool running = true;
		while ( running )
		{
			keyEvent( monitor, running );
			if (!running)
				break;
			monitor->draw();
			usleep(100000);
		}
	}
	else if (options.windowed())
		monitor = new WindowedDisplay();
	else
		options.printErrors();
	return 0;
}
