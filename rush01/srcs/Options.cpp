#include "Options.hpp"

Options::Options(int ac, char **av) : size(ac - 1), options(std::vector<std::string>(this->size)), window(false), shelled(true)
{
	for (int i = 1; i < ac; ++i)
		this->options[i].assign(std::string(av[i]));
	if (std::find(this->options.begin(), this->options.end(), "-g") != this->options.end())
	{
		this->window = true;
		this->shelled = false;
	}
	if (std::find(this->options.begin(), this->options.end(), "-s") != this->options.end())
		this->shelled = true;
	if (this->shelled && this->window)
		this->shelled = this->window = false;
}
