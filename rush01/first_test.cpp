#include "TUI_Module.hpp"
#include <list>

WINDOW			*createWin(int h, int w, int x, int y){

	WINDOW *local_win;
	local_win = newwin(h, w, x, y);
	box(local_win, 0 , 0); 
	wrefresh(local_win); 		
	return local_win;
}

std::string		keyEvent(){
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

void			dispatch(std::list<TUI_Module *> &li)
{
	int		x = 0;
	std::list<TUI_Module*>::const_iterator	it;
	for (it = li.begin(); it != li.end(); ++it)
	{
		if ((*it)->win)
			delwin((*it)->win);
		(*it)->win = createWin( (*it)->ok_height, 20, x, 2 );
		x += (*it)->ok_height;
	}
}

void			insert(std::list<TUI_Module *> &li)
{
	li.push_front( new TUI_Module );
	dispatch( li );
}

int		main( void )
{
	// init ncurses
	initscr();
	cbreak();
	noecho();
	refresh();

	std::list<TUI_Module *> li;
	li.push_front( new TUI_Module );
	(*li.begin())->active = true;
	li.push_front( new TUI_Module );
	li.push_front( new TUI_Module );
	li.push_front( new TUI_Module );
	dispatch(li);
	std::list<TUI_Module*>::const_iterator	it;
	for (it = li.begin(); it != li.end(); ++it)
	{
		(*it)->content = "bonjour";
		(*it)->update();
		(*it)->draw();
	}
	//TUI_Module	mymodule( createWin(3, 20, 2, 2 ));
	//wprintw( mymodule.win, "coucou" );
	//refresh();
	//wrefresh(mymodule.win);
	//refresh();
	getch();
	insert(li);
	getch();

	// closing, freeing & returning
	endwin();
	return ( 0 );
}
