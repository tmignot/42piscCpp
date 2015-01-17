#include "ShellDisplay.hpp"

WINDOW			*ShellDisplay::createWin(int h, int w, int x, int y){

	WINDOW *local_win;
	local_win = newwin(h, w, x, y);
	box(local_win, 0 , 0); 
	wrefresh(local_win); 		
	return local_win;
}

std::string		ShellDisplay::keyEvent(){
	timeout(0);
	int  ch  = getch();
	switch (ch){
		case 'i': // insertion apres le module courant
			return "i";
		case 'I': // insertion apres le module courant
			return "I";
		case 'a': // insertion apres le module courant
			return "i";
		case 'A': // insertion apres le module courant
			return "I";
		case 27:	// escape
			if (getch() == -1)
				return "escape";
			return "segfault";
		default:
			return "je met ce que je veux!";
	}
}

void			ShellDisplay::dispatch(std::list<TUI_Module *> &li)
{
	int		x = 0;
	std::list<TUI_Module*>::const_iterator	it;
	for (it = li.begin(); it != li.end(); ++it)
	{
		if ((*it)->win)
			delwin((*it)->win);
		(*it)->win = createWin( (*it)->ok_height, 200, x, 2 );
		x += (*it)->ok_height;
	}
}

void			ShellDisplay::insert(std::list<TUI_Module *> &li)
{
	li.push_front( new TUI_Module( new Hostname ) );
	//dispatch( li );
}

int		ShellDisplay::sillymain( void )
{
	// init ncurses
	initscr();
	cbreak();
	noecho();
	refresh();

	std::list<TUI_Module *> li;
	insert(li);
	//(*li.begin())->active = true;
	/*
	insert(li);
	insert(li);
	*/
	std::list<TUI_Module*>::const_iterator	it;
	/*
	for (it = li.begin(); it != li.end(); ++it)
	{
		(*it)->update();
		(*it)->draw();
	}
	*/
	getch();
	// closing, freeing & returning
	endwin();
	return ( 0 );
}

ShellDisplay::ShellDisplay(void) : IMonitorDisplay() {}
ShellDisplay::ShellDisplay(ShellDisplay const &shell) : IMonitorDisplay() {*this = shell;}
ShellDisplay::~ShellDisplay(void) {}
ShellDisplay				&ShellDisplay::operator=(ShellDisplay const&) {return (*this);}
