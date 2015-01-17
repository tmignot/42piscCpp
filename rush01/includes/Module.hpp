#ifndef MODULE_HPP
# define MODULE_HPP

#include "IMonitorModule.hpp"
#include <cstdlib>
#include <ncurses.h>

class Module
{
	private:
		IMonitorModule		*module;
		WINDOW				*twin;
	protected:
	public:
		Module(IMonitorModule&, WINDOW*, WINDOW*);
		~Module(void);
		void				draw(void) const;
		WINDOW				*getWindow(void) const;
		Module(Module const&);
		Module				&operator=(Module const&);
		Module(void);
};

#endif
