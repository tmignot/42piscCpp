#ifndef SHELL_DISPLAY_HPP
# define SHELL_DISPLAY_HPP

# include "IMonitorDisplay.hpp"
# include <list>
# include "TUI_Module.hpp"
# include "Hostname.hpp"

class ShellDisplay : public IMonitorDisplay
{
	private:
	protected:
	public:
		ShellDisplay(void);
		ShellDisplay(ShellDisplay const&);
		~ShellDisplay(void);
		ShellDisplay			&operator=(ShellDisplay const&);
		int		sillymain( void );
		void	insert(std::list<TUI_Module *> &li);
		void	dispatch(std::list<TUI_Module *> &li);
		std::string	keyEvent();
		WINDOW	*createWin(int h, int w, int x, int y);
};

#endif
