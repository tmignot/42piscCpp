#ifndef OPTIONS_HPP
# define OPTIONS_HPP

#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

class Options
{
	private:
		int								size;
		std::vector<std::string>		options;
		bool							window;
		bool							shelled;
		Options(Options const&);
		Options(void);
		Options							&operator=(Options const&);
	protected:
	public:
		Options(int, char**);
		~Options(void);
		bool							shell(void);
		bool							windowed(void);
		void							printErrors(void);
		void							printWarnings(void);
};

#endif
