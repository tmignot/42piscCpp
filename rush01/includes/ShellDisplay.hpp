#ifndef SHELL_DISPLAY_HPP
# define SHELL_DISPLAY_HPP

# include "IMonitorDisplay.hpp"
# include "Module.hpp"
# include <list>

class ShellDisplay : public IMonitorDisplay
{
	private:
		std::list<Module*>		modules;
		WINDOW					*win;
		int						h;
		int						w;
		int						posy;
		int						posx;
	protected:
	public:
		ShellDisplay(void);
		ShellDisplay(int, int, int, int);
		ShellDisplay(ShellDisplay const&);
		virtual ~ShellDisplay(void);
		ShellDisplay			&operator=(ShellDisplay const&);
		virtual void			draw(void);
		virtual void			addModule(Module &module);
};

#endif
