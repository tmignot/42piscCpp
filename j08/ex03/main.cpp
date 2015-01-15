#include "Mindopen.hpp"
#include <fstream>
#include <streambuf>

int			main(int ac, char **av)
{
	Mindopen		bf;

	if (ac == 2)
	{
		std::ifstream	fs(av[1]);
		if (fs)
		{
			std::string		str((std::istreambuf_iterator<char>(fs)), std::istreambuf_iterator<char>());
			bf.ToDo(str);
			fs.close();
		}
	}
	return (0);
}
