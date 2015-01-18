#include "Module.hpp"

Module::Module(void) : module(NULL), twin(NULL), undefined("UNDEFINED"), data(std::vector<std::string>()), w(0), h(0) {}

Module::Module(IMonitorModule &module, WINDOW *lastwin, WINDOW *displaywin) : module(&module), twin(NULL), undefined("UNDEFINED"), data(std::vector<std::string>()), w(0), h(0)
{
	this->data = this->module->getData();
	this->w = this->getWidth();
	this->h = this->getHeight();
	twin = this->initWindow(lastwin, displaywin);
}

Module::Module(Module const &module) {*this = module;}

Module					&Module::operator=(Module const &module)
{
	this->module = module.module;
	this->twin = module.twin;
	return (*this);
}


Module::~Module(void)
{
	if (this->twin)
	{
		wborder(this->twin, ' ', ' ', ' ',' ',' ',' ',' ',' ');
		wrefresh(this->twin);
		delwin(this->twin);
	}
}

void					Module::draw(void)
{
	this->module->update();
	this->data = this->module->getData();

	if (this->twin)
	{
		box(this->twin, 0, 0);
		for (unsigned int i = 0; i < this->data.size(); ++i)
		{
			printMiddle(this->twin, i + 1, this->data[i]);
		}
		wrefresh(this->twin);
	}
}

int						Module::getHeight(void) const
{
	return (this->data.size());
}

WINDOW					*Module::getWindow(void) const
{
	return (this->twin);
}

bool					Module::operator==(Module const &module)
{
	return (this->module->getName() == module.module->getName());
}

std::string const		&Module::getName(void) const
{
	return (this->module ? module->getName() : this->undefined);
}

int								Module::getWidth(void) const
{
	int			ret = 0;

	for (std::vector<std::string>::const_iterator it = this->data.begin(); it != this->data.end(); ++it)
	{
		if ((*it).length() > static_cast<unsigned int>(ret))
			ret = (*it).length();
	}
	return (ret);
}

WINDOW							*Module::initWindow(WINDOW *lastwin, WINDOW *displaywin)
{
	int							w = this->w + 2;
	int							h = this->h + 2;
	WINDOW						*local_win = NULL;
	if (lastwin)
	{
		if (getbegy(lastwin) + getmaxy(lastwin) + h + 1 < getbegy(displaywin) + getmaxy(displaywin))
		{
			if (getbegx(lastwin) + 1 + w < getbegx(displaywin) + getmaxx(displaywin))
				local_win = newwin(h, w, getbegy(displaywin) + getbegy(lastwin) + getmaxy(lastwin), getbegx(displaywin) + getbegx(lastwin));
		}
		else
		{
			if (getbegx(lastwin) + getmaxx(lastwin) + 1 + w < getbegx(displaywin) + getmaxx(displaywin))
				local_win = newwin(h, w, getbegy(displaywin) + 1, getbegx(displaywin) + getbegx(lastwin) + getmaxx(lastwin) + 1);
		}
	}
	else
		local_win = newwin(h, w, getbegy(displaywin) + 1, getbegx(displaywin) + 1);
	if (local_win)
	{
		box(local_win, 0, 0);
		wrefresh(local_win);
	}
	return (local_win);
}

void							Module::setDimensions(int h, int w, WINDOW *lastwin, WINDOW *displaywin)
{
	this->h = h;
	this->w = w;
	WINDOW			*tmp = this->initWindow(lastwin, displaywin);
	//wclear(this->twin);
	//wborder(this->twin, ' ', ' ', ' ',' ',' ',' ',' ',' ');
	//wrefresh(this->twin);
	delwin(this->twin);
	this->twin = tmp;
}

void						Module::printMiddle(WINDOW *win, int y, std::string const & s) const{
	mvwprintw(win, y, (getmaxx(win) - s.size()) / 2, s.c_str());
}
