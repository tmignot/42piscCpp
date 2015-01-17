#include "ShellDisplay.hpp"

ShellDisplay::ShellDisplay(void) : IMonitorDisplay() {}
ShellDisplay::ShellDisplay(int h, int w, int posy, int posx) : IMonitorDisplay(), modules(std::list<Module*>()), h(h), w(w), posy(posy), posx(posx)
{
	initscr();
	noecho();
	curs_set(0);
	this->win = newwin(h, w, posy, posx);
}
ShellDisplay::ShellDisplay(ShellDisplay const &shell) : IMonitorDisplay() {*this = shell;}
ShellDisplay::~ShellDisplay(void)
{
	endwin();
}
ShellDisplay				&ShellDisplay::operator=(ShellDisplay const&) {return (*this);}
void						ShellDisplay::addModule(Module &module)
{
	this->modules.push_back(&module);
}
void						ShellDisplay::draw(void)
{
	wclear(this->win);
	for (std::list<Module*>::const_iterator it = this->modules.begin(); it != this->modules.end(); ++it)
	{
		(*it)->draw();
		refresh();
	}
}
