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
		WINDOW							*win;
		std::list<Module*>				modules;
		std::map<char,bool>				inst_mods;
		std::map<char,IMonitorModule*>	iModules;
		void							addModule(char);
		void							removeModule(char);
		int								getMaxHeight(void);
		int								getMaxWidth(void);
		std::list<Module*>::iterator	find(Module*);
	protected:
	public:
		ShellDisplay(void);
		ShellDisplay(ShellDisplay const&);
		~ShellDisplay(void);
		ShellDisplay					&operator=(ShellDisplay const&);
		virtual void					draw(void) const;
		virtual std::string const		&parseCommand(char code);
};

#endif
