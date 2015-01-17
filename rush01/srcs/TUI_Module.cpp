#include "TUI_Module.hpp"

unsigned int	TUI_Module::ok_height = 5;
unsigned int	TUI_Module::min_height = 3;

TUI_Module::TUI_Module(void)
	: active (false)
{}
TUI_Module::TUI_Module( WINDOW *w )
	: win(w)
{}
TUI_Module::TUI_Module( IMonitorModule *m )
	: mod(m)
{}

TUI_Module::TUI_Module(TUI_Module const &module) {*this = module;}
TUI_Module::~TUI_Module(void) {}
TUI_Module	&TUI_Module::operator=(TUI_Module const&) {return (*this);}

void		TUI_Module::update( )
{
	if ( active )
	{
		wborder( win,'#', '#', '#', '#', '#', '#', '#', '#' );
		wrefresh(win); 		
	}
			   //	ACS_CKBOARD, ACS_CKBOARD, ACS_CKBOARD, ACS_CKBOARD, ACS_CKBOARD, ACS_CKBOARD, ACS_CKBOARD, ACS_CKBOARD );
	/*
	else
		wborder( win, ACS_VLINE,
						ACS_VLINE,
						ACS_HLINE,
						ACS_HLINE,
						ACS_ULCORNER,
						ACS_URCORNER,
						ACS_LLCORNER,
						ACS_LRCORNER );
						*/
}

void		TUI_Module::draw( )
{
	mvwprintw(win, 1, 1, "voila");//coucou.c_str());
	//std::string	coucou = (mod->getData())[0];
	//mvwprintw(win, 1, 1, coucou.c_str());
	wrefresh(win);
}
