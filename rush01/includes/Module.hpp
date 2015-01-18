#ifndef MODULE_HPP
# define MODULE_HPP

#include "IMonitorModule.hpp"
#include <cstdlib>
#include <ncurses.h>
#include <typeinfo>

class Module
{
	private:
		IMonitorModule		*module;
		WINDOW				*twin;
	protected:
		std::string const	undefined;
	public:
		Module(IMonitorModule&, WINDOW*, WINDOW*);
		~Module(void);
		void				draw(void) const;
		WINDOW				*getWindow(void) const;
		Module(Module const&);
		Module				&operator=(Module const&);
		bool				operator==(Module const&);
		std::string const	&getName(void) const;
		Module(void);
};

#endif
