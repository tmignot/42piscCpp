#include "ShellDisplay.hpp"

ShellDisplay::ShellDisplay(void) : IMonitorDisplay(), win(NULL), modules(std::list<Module*>()), inst_mods(std::map<char, bool>())
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
	for(std::list<Module*>::iterator it = this->modules.begin(); it != this->modules.end(); ++it)
	{
		delete *it;
		it = this->modules.erase(it);
	}
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
	for (std::list<Module*>::const_iterator it = this->modules.begin(); it != this->modules.end(); ++it)
	{
		(const_cast<Module*>(*it))->draw();
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
	module = new Module(*(this->iModules[code]), NULL, this->win, 0);
	int			h = (module->getHeight() > this->getMaxHeight() ? module->getHeight() : this->getMaxHeight()), w = (module->getWidth() > this->getMaxWidth() ? module->getWidth() : this->getMaxWidth());
	if (this->modules.size())
	{
		if (!(this->modules.front()->getWidth() >= w && this->modules.front()->getHeight() >= h))
		{
			Module			*tmp = NULL;
			for (std::list<Module*>::iterator it = this->modules.begin(); it != this->modules.end(); ++it)
			{
				if (tmp)
					((*it))->setDimensions(h, w, tmp->getWindow(), this->win);
				else
					((*it))->setDimensions(h, w, NULL, this->win);
				tmp = const_cast<Module*>(*it);
			}
		}
		int i;
		for (i = 0; i < 100 ; i++)
		{
			if (this->blocFree(i))
				break;
		}
		module->setBlocP(i);
	}
	this->inst_mods[code] = true;
	if (this->modules.size())
		module->setDimensions(h, w, this->modules.back()->getWindow(), this->win);
	else
		module->setDimensions(h, w, NULL, this->win);
	this->modules.push_back(module);
}

bool							ShellDisplay::blocFree(int b)
{
	for(std::list<Module*>::iterator it = this->modules.begin(); it != this->modules.end(); ++it)
	{
		if ((*it)->getBlocP() == b)
			return false;
	}
	return true;
}

std::list<Module*>::iterator	ShellDisplay::find(Module *module)
{
	std::list<Module*>::iterator it;
	for (it = this->modules.begin(); it != this->modules.end(); ++it)
	{
		if (*(*it) == *module)
			break;
	}
	return (it);
}
void						ShellDisplay::removeModule( char code )//IMonitorModule &imodule)
{
	Module									*modulefirst, *modulelast;
	modulelast = new Module(*(this->iModules[code]), this->modules.back()->getWindow(), this->win, 0);
	modulefirst = new Module(*(this->iModules[code]), NULL, this->win, 0);
	std::list<Module*>::iterator		it = this->find(modulefirst);
	if (it != this->modules.end())
	{
		delete *it;
		this->modules.erase(it);
	}
	else
	{
		it = this->find(modulelast);
		if (it != this->modules.end())
		{
			delete *it;
			this->modules.erase(it);
		}
	}
	this->inst_mods[code] = false;
	delete modulefirst;
	delete modulelast;
}

int							ShellDisplay::getMaxHeight(void)
{
	int				ret = 0;

	for (std::list<Module*>::const_iterator it = this->modules.begin(); it != this->modules.end(); ++it)
	{
		if ((*it)->getHeight() > ret)
			ret = (*it)->getHeight();
	}
	return (ret);
}

int							ShellDisplay::getMaxWidth(void)
{
	int				ret = 0;

	for (std::list<Module*>::const_iterator it = this->modules.begin(); it != this->modules.end(); ++it)
	{
		if ((*it)->getWidth() > ret)
			ret = (*it)->getWidth();
	}
	return (ret);
}
