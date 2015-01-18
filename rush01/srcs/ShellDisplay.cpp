#include "ShellDisplay.hpp"

ShellDisplay::ShellDisplay(void) : IMonitorDisplay(), win(NULL), modules(std::list<Module>()), inst_mods(std::map<char, bool>())
{
	initscr();
	nodelay(stdscr, TRUE);
	noecho();
	curs_set(0);
	this->win = newwin(60, 60, 0, 0);
	box(this->win, 0, 0);
	this->inst_mods['h'] = false;
	this->inst_mods['c'] = false;
	this->inst_mods['t'] = false;
	this->inst_mods['r'] = false;
	this->inst_mods['o'] = false;
	this->inst_mods['n'] = false;
	this->iModules['h'] = new Hostname();
	this->iModules['c'] = new CPU();
	this->iModules['t'] = new Time();
	this->iModules['r'] = new RAM();
	this->iModules['o'] = new OS();
	this->iModules['n'] = new Network();
	wrefresh(this->win);
}
ShellDisplay::ShellDisplay(ShellDisplay const &shell) : IMonitorDisplay() {*this = shell;}
ShellDisplay::~ShellDisplay(void) {
	//freeing module objects instanciated in addModule
	this->modules.clear();
	delete this->iModules['h'];
	delete this->iModules['c'];
	delete this->iModules['t'];
	delete this->iModules['r'];
	delete this->iModules['o'];
	delete this->iModules['n'];
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
	for (std::list<Module>::const_iterator it = this->modules.begin(); it != this->modules.end(); ++it)
	{
		(*(const_cast<Module*>(&(*it)))).draw();
	}
}
std::string const			&ShellDisplay::parseCommand( char code )
{
	if ( this->inst_mods[code] ) // test if we already instanciated this specific module
		this->removeModule(code);
	else
		this->addModule(code);
	return (this->iModules[code]->getName());
}
void						ShellDisplay::addModule( char code )//IMonitorModule &imodule)
{
	Module			*module;
	if (this->modules.size())
	{
		module = new Module(*(this->iModules[code]), this->modules.back().getWindow(), this->win);
	}
	else
	{
		module = new Module(*(this->iModules[code]), NULL, this->win);
	}
	this->modules.push_back(*module);
	this->inst_mods[code] = true;
}
void						ShellDisplay::removeModule( char code )//IMonitorModule &imodule)
{
	Module									*modulefirst, *modulelast;
	modulelast = new Module(*(this->iModules[code]), this->modules.back().getWindow(), this->win);
	modulefirst = new Module(*(this->iModules[code]), NULL, this->win);
	std::list<Module>::iterator		it = std::find(this->modules.begin(), this->modules.end(), *modulefirst);
	if (it != this->modules.end())
		this->modules.erase(it);
	else
	{
		it = std::find(this->modules.begin(), this->modules.end(), *modulelast);
		if (it != this->modules.end())
			this->modules.erase(it);
	}
	this->inst_mods[code] = false;
	delete modulefirst;
	delete modulelast;
}
