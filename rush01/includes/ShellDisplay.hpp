#ifndef SHELL_DISPLAY_HPP
# define SHELL_DISPLAY_HPP

# include "IMonitorDisplay.hpp"
# include <ncurses.h>
# include <list>
# include "Module.hpp"

class ShellDisplay : public IMonitorDisplay
{
	private:
		WINDOW					*win;
		std::list<Module*>		modules;
	protected:
	public:
		ShellDisplay(void);
		ShellDisplay(ShellDisplay const&);
		~ShellDisplay(void);
		ShellDisplay			&operator=(ShellDisplay const&);
		virtual void			draw(void) const;
		virtual void			addModule(IMonitorModule&);
};

#endif
