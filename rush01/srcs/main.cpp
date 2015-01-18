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

void	handle_sdl_events(IMonitorDisplay* mon, bool& running){
	SDL_Event e;
	while (SDL_PollEvent(&e)) {
		if (e.type == SDL_KEYDOWN) {
			switch (e.key.keysym.sym) {
				case SDLK_ESCAPE: running = false; break;
				default: break;
			}
		}
	}
	(void)mon;
}

int		main(int ac, char **av)
{
	Options				options(ac, av);
	bool running = true;
	
	if (options.shell())
	{
		ShellDisplay* monitor = NULL;
		monitor = new ShellDisplay();
		monitor->draw();
		while ( running )
		{
			keyEvent( monitor, running );
			if (!running)
				break;
			monitor->draw();
			usleep(100000);
		}
	}
	else if (options.windowed()) {
		WindowedDisplay* monitor;
		monitor = new WindowedDisplay();
		CPU 		cpu;
		RAM			ram;
		Hostname	host;
		Network		net;
		OS			os;
		Time		time;
		monitor->addModule(&time);
		monitor->addModule(&host);
		monitor->addModule(&os);
		monitor->addModule(&cpu);
		monitor->addModule(&ram);
		monitor->addModule(&net);
		while (running) {
			handle_sdl_events(monitor, running);
			monitor->update();
			monitor->draw();
			SDL_Delay(100);
		}
	}
	else
		options.printErrors();
	return 0;
}
