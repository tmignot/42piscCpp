#ifndef MODULE_HPP
# define MODULE_HPP

#include "IMonitorModule.hpp"
#include <cstdlib>
#include <string>
#include <vector>
#include <ncurses.h>

class Module
{
	private:
		IMonitorModule		*module;
		WINDOW				*twin;
		int					h;
		int					w;
		int					posy;
		int					posx;
		WINDOW				*create_newtwin(int, int, int, int);
	protected:
	public:
		Module(void);
		Module(IMonitorModule&, bool shell, int, int, int, int);
		~Module(void);
		Module(Module const&);
		Module				&operator=(Module const&);
		void				draw(void) const;
};

#endif
