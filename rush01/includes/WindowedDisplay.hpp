#ifndef WINDOWED_DISPLAY_HPP
# define WINDOWED_DISPLAY_HPP

# include "IMonitorDisplay.hpp"
# include "SDL2/SDL.h"
# include "SDL2/SDL_ttf.h"

class WindowedDisplay : public IMonitorDisplay
{
	private:
		std::string						name;
		SDL_Window*						window;
		SDL_Surface*					surface;
		TTF_Font*						font;
		std::vector<IMonitorModule*>	modules;
		std::vector<SDL_Surface*>		text;
		SDL_Color						textColor;
	protected:
	public:
		WindowedDisplay(void);
		WindowedDisplay(WindowedDisplay const&);
		~WindowedDisplay(void);
		WindowedDisplay					&operator=(WindowedDisplay const&);
		virtual void					draw(void) const;
		virtual std::string const		&parseCommand(char code);
		void							addModule(IMonitorModule*);
		void							update();
		void							removeModule(char);
};

#endif
