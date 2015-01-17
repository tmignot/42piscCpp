#ifndef SHELL_DISPLAY_HPP
# define SHELL_DISPLAY_HPP

# include "IMonitorDisplay.hpp"

class ShellDisplay : public IMonitorDisplay
{
	private:
	protected:
	public:
		ShellDisplay(void);
		ShellDisplay(ShellDisplay const&);
		~ShellDisplay(void);
		ShellDisplay			&operator=(ShellDisplay const&);
};

#endif
