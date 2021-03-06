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
		int								blocp;
	protected:
	public:
		Module(IMonitorModule&, WINDOW*, WINDOW*, int);
		~Module(void);
		void				draw(void);
		int					getWidth(void) const;
		int					getHeight(void) const;
		void				setBlocP(int b);
		int					getBlocP(void);
		WINDOW				*getWindow(void) const;
		Module(Module const&);
		Module				&operator=(Module const&);
		bool				operator==(Module const&);
		std::string const	&getName(void) const;
		Module(void);
		WINDOW				*initWindow(WINDOW*, WINDOW*);
		void				setDimensions(int, int, WINDOW*, WINDOW*);
};

#endif
