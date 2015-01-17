#ifndef TUI__MODULE_HPP
# define TUI__MODULE_HPP

# include <ncurses.h>
# include <string>
# include "IMonitorModule.hpp"

class TUI_Module
{
	private:
		unsigned int	width;
		unsigned int	height;
	protected:
		TUI_Module(TUI_Module const&);
	public:
		TUI_Module(void);
		TUI_Module( WINDOW *w );
		TUI_Module( IMonitorModule *m );
		~TUI_Module(void);
		TUI_Module				&operator=(TUI_Module const&);

		IMonitorModule	*mod;
		bool			active;
		WINDOW			*win;
		std::string		content;
		void		draw( );
		void		update( );
		static unsigned int	ok_height;
		static unsigned int	min_height;
};

#endif
