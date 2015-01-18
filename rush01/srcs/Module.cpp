#include "Module.hpp"

Module::Module(void) : module(NULL), twin(NULL), undefined("UNDEFINED"), data(std::vector<std::string>()){}

Module::Module(IMonitorModule &module, WINDOW *lastwin, WINDOW *displaywin) : module(&module), twin(NULL), undefined("UNDEFINED"), data(std::vector<std::string>())
{
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
	this->data = this->module->getData();
	int							w = this->getWidth() + 2;
	int							h = data.size() + 2;
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
