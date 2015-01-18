#ifndef WINDOWED_DISPLAY_HPP
# define WINDOWED_DISPLAY_HPP

# include "IMonitorDisplay.hpp"

class WindowedDisplay : public IMonitorDisplay
{
	private:
	protected:
	public:
		WindowedDisplay(void);
		WindowedDisplay(WindowedDisplay const&);
		~WindowedDisplay(void);
		WindowedDisplay			&operator=(WindowedDisplay const&);
		virtual void			draw(void) const;
		virtual void			addModule(char code);
};

#endif
