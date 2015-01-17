#include "Module.hpp"

Module::Module(void) : module(NULL), twin(NULL) {}

Module::Module(IMonitorModule &module, WINDOW *lastwin, WINDOW *displaywin) : module(&module), twin(NULL)
{
	twin = this->module->initWindow(lastwin, displaywin);
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
		//this->twin = NULL;
	}
}

void					Module::draw(void) const
{
	//this->module->update();
	std::vector<std::string>		data = this->module->getData();

	for (unsigned int i = 0; i < data.size(); ++i)
	{
		mvwprintw(this->twin, i + 1, 1, data[i].c_str());
	}
	wrefresh(this->twin);
}

WINDOW					*Module::getWindow(void) const
{
	return (this->twin);
}
