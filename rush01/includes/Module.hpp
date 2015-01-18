#ifndef MODULE_HPP
# define MODULE_HPP

#include "IMonitorModule.hpp"
#include <cstdlib>
#include <ncurses.h>
#include <typeinfo>

class Module
{
	private:
		IMonitorModule					*module;
		WINDOW							*twin;
		std::string const				undefined;
		std::vector<std::string>		data;
		int								w;
		int								h;
	protected:
	public:
		Module(IMonitorModule&, WINDOW*, WINDOW*);
		~Module(void);
		void				draw(void);
		int					getWidth(void) const;
		int					getHeight(void) const;
		WINDOW				*getWindow(void) const;
		Module(Module const&);
		Module				&operator=(Module const&);
		bool				operator==(Module const&);
		std::string const	&getName(void) const;
		Module(void);
		WINDOW				*initWindow(WINDOW*, WINDOW*);
		void				setDimensions(int, int, WINDOW*, WINDOW*);
		void				printMiddle(WINDOW *, int, std::string const &) const;
};

#endif
