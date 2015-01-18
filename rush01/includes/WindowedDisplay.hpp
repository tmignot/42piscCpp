#ifndef WINDOWED_DISPLAY_HPP
# define WINDOWED_DISPLAY_HPP

# include "IMonitorDisplay.hpp"

class WindowedDisplay : public IMonitorDisplay
{
	private:
		std::string						name;
		void							addModule(char);
		void							removeModule(char);
	protected:
	public:
		WindowedDisplay(void);
		WindowedDisplay(WindowedDisplay const&);
		~WindowedDisplay(void);
		WindowedDisplay					&operator=(WindowedDisplay const&);
		virtual void					draw(void) const;
		virtual std::string const		&parseCommand(char code);
};

#endif
