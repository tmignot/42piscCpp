#include "Module.hpp"

Module::Module(void) {}
Module::Module(Module const &module) {*this = module;}
Module::~Module(void) {}
Module				&Module::operator=(Module const&) {return (*this);}
