#include "Module.hpp"

Module::Module(void) : module(NULL) {}
Module::~Module(void)
{
	if (this->module)
		delete this->module;
}
