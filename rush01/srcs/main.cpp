#include "GKrellM.hpp"

int		main(int ac, char **av)
{
	IMonitorDisplay		*monitor = NULL;
	std::string			mode;
	
	if (ac == 1 || (mode = std::string(av[1])) == "-s")
		monitor = new ShellDisplay();
	else if (ac >= 2 && mode == "-g")
		monitor = new WindowedDisplay();
	else
		std::cout << "Invalid display mode option" << std::endl << "Please use -g or -s option to request a display mode" << std::endl;
	if (monitor)
		delete monitor;
	return (0);
}
