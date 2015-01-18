#include "Module.hpp"

Module::Module(void) : module(NULL), twin(NULL), undefined("UNDEFINED"), data(std::vector<std::string>()), w(0), h(0), blocp(0) {}

Module::Module(IMonitorModule &module, WINDOW *lastwin, WINDOW *displaywin, int blocp) : module(&module), twin(NULL), undefined("UNDEFINED"), data(std::vector<std::string>()), w(0), h(0), blocp(blocp)
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
			mvwprintw(this->twin, i + 1, 1, this->data[i].c_str());
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
	int							blocp = this->blocp, column = 0;
	lastwin = lastwin;
	while (blocp * this->h + h > getbegy(displaywin) + getmaxy(displaywin) - 2)
	{
		blocp -= (getbegy(displaywin) + getmaxy(displaywin)) / this->h;
		column++;
	}
	if (column * this->w + w < getbegx(displaywin) + getmaxx(displaywin) - 2)
		local_win = newwin(h, w, blocp * h + 1, column * w + 1);
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
	delwin(this->twin);
	this->twin = tmp;
}
 void							Module::setBlocP(int b)
{
	this->blocp = b;
}

int								Module::getBlocP(void)
{
	return (this->blocp);
}
