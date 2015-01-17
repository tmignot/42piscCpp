#include "Options.hpp"

Options::Options(int ac, char **av) : size(ac - 1), options(std::vector<std::string>(this->size)), window(false), shelled(true)
{
	for (int i = 1; i < ac; ++i)
		this->options.push_back(std::string(av[i]));
	if (std::find(this->options.begin(), this->options.end(), "-g") != this->options.end())
	{
		this->window = true;
		this->shelled = false;
	}
	if (std::find(this->options.begin(), this->options.end(), "-s") != this->options.end())
		this->shelled = true;
	if (this->shelled && this->window)
		this->shelled = this->window = false;
	this->printWarnings();
}

Options::~Options(void) {}

bool					Options::shell(void)
{
	return (this->shelled);
}

bool					Options::windowed(void)
{
	return (this->window);
}

void					Options::printErrors(void)
{
	if (!this->shelled && !this->window)
		std::cout << "Invalid display mode, please use either -s or -g" << std::endl;
}

void					Options::printWarnings(void)
{
	if (this->size > 1)
		std::cout << "Warning: Too many arguments" << std::endl;
}
