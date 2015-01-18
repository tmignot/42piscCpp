#ifndef SHELL_DISPLAY_HPP
# define SHELL_DISPLAY_HPP

# include "IMonitorDisplay.hpp"
# include <ncurses.h>
# include <list>
# include <map>
# include "Module.hpp"
# include "GKrellM.hpp"

class ShellDisplay : public IMonitorDisplay
{
	private:
		WINDOW					*win;
		std::list<Module*>		modules;
		std::map<char,bool>		inst_mods;
	protected:
	public:
		ShellDisplay(void);
		ShellDisplay(ShellDisplay const&);
		~ShellDisplay(void);
		ShellDisplay			&operator=(ShellDisplay const&);
		virtual void			draw(void) const;
		//virtual void			addModule(IMonitorModule&);
		virtual void			addModule(char code);
};

#endif
