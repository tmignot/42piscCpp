#include "ShellDisplay.hpp"

ShellDisplay::ShellDisplay(void) : IMonitorDisplay(), win(NULL), modules(std::list<Module*>())
{
	initscr();
	nodelay(stdscr, TRUE);
	noecho();
	curs_set(0);
	this->win = newwin(60, 60, 0, 0);
	box(this->win, 0, 0);
	wrefresh(this->win);
}
ShellDisplay::ShellDisplay(ShellDisplay const &shell) : IMonitorDisplay() {*this = shell;}
ShellDisplay::~ShellDisplay(void) {endwin();}
ShellDisplay				&ShellDisplay::operator=(ShellDisplay const &display)
{
	this->win = display.win;
	this->modules = display.modules;
	return (*this);
}
void						ShellDisplay::draw(void) const
{
	clear();
	box(this->win, 0, 0);
	wrefresh(this->win);
	for (std::list<Module*>::const_iterator it = this->modules.begin(); it != this->modules.end(); ++it)
	{
		(*it)->draw();
	}
}
void						ShellDisplay::addModule(IMonitorModule &imodule)
{
	Module			*module;
	if (this->modules.size())
		module = new Module(imodule, this->modules.back()->getWindow(), this->win);
	else
		module = new Module(imodule, NULL, this->win);
	this->modules.push_back(module);
}
