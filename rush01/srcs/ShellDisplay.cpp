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
ShellDisplay::~ShellDisplay(void) {
	//freeing module objects instanciated in addModule
	std::list<Module*>::const_iterator	it;
	for ( it = modules.begin(); it != modules.end(); ++it )
		delete *it;
	endwin();
}
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
void						ShellDisplay::addModule( char code )//IMonitorModule &imodule)
{
	Module			*module;
	IMonitorModule	*imodule = NULL;
	if ( inst_mods.count(code) ) // test if we already instanciated this specific module
		return ;				   // because we don't want to instanciate more than one
								   // of each type
	switch ( code ) {
		case 't':	//time
			imodule = new Time();
			break;
		case 'h':	//hostname
			imodule = new Hostname();
			break;
		case 'c':	//cpu
			imodule = new CPU();
			break;
		case 'o':	//os
			imodule = new OS();
			break;
		default:	//yolo mode
			return ;
	}
	if (this->modules.size())
	{
		module = new Module(*imodule, this->modules.back()->getWindow(), this->win);
	}
	else
	{
		module = new Module(*imodule, NULL, this->win);
	}
	this->modules.push_back(module);
	inst_mods.insert( std::pair<char, bool>( code, true ) );
}
