#include "WindowedDisplay.hpp"

WindowedDisplay::WindowedDisplay(void) : IMonitorDisplay(), name("FUCK YOU") {
	SDL_Init(SDL_INIT_VIDEO);
	TTF_Init();
	window = SDL_CreateWindow("ft_gkrellm", 0, 0, 140, 550, 0);
	surface = SDL_GetWindowSurface(window);		
	font = TTF_OpenFont("font/consolas.ttf", 12);
	textColor.r = 155;
	textColor.g = 255;
	textColor.b = 155;
	textColor.a = 155;
}

WindowedDisplay::WindowedDisplay(WindowedDisplay const &windowed) : IMonitorDisplay() {*this = windowed;}
WindowedDisplay::~WindowedDisplay(void) {}
WindowedDisplay				&WindowedDisplay::operator=(WindowedDisplay const&) {return (*this);}

void						WindowedDisplay::update() {
}

void						WindowedDisplay::draw(void)  const {
	std::vector<IMonitorModule*>::const_iterator it;
	SDL_Rect rect;
	rect.x = rect.y = 0;
	rect.w = 300;
	rect.h = 550;
	SDL_FillRect(surface, &rect, 0x000000);
	SDL_Color aColor = textColor;
	int i=0;
	for (it = modules.begin(); it != modules.end(); ++it) {
		(*it)->update();
		std::vector<std::string> mData = (*it)->getData();
		std::vector<std::string>::iterator jt;
		int j = 0;
		for (jt = mData.begin(); jt != mData.end(); ++jt)  {
			if (!j)
				aColor.r  = aColor.b = 255;
			else
				aColor = textColor;
			if (i == 3 && j > 2) {
				*jt = jt->substr(0, jt->size() - 3);
			}
			SDL_Surface* s = TTF_RenderText_Blended(font, (*jt).c_str(), aColor);
			if (i == 0)
				rect.y = 10 + 20 * j;
			if (i == 1)
				rect.y = 90 + 20 * j;
			if (i == 2)
				rect.y = 150 + 20 * j;
			if (i == 3)
				rect.y = 210 + 20 * j;
			if (i == 4)
				rect.y = 370 + 20 * j;
			if (i == 5)
				rect.y = 490 + 20 * j;
			rect.w = 300;
			rect.h = 100;
			SDL_BlitSurface(s, NULL, surface, &rect);
			SDL_FreeSurface(s);
			j++;
		}
		i++;
	}
	SDL_UpdateWindowSurface(window);
}

std::string const& WindowedDisplay::parseCommand(char) { return *(new std::string("")); }

void						WindowedDisplay::addModule(IMonitorModule* m) {
	modules.push_back(m);
}
