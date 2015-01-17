#include "IMonitorModule.hpp"

IMonitorModule::IMonitorModule(void) {}
IMonitorModule::IMonitorModule(IMonitorModule const &module) {*this = module;}
IMonitorModule::~IMonitorModule(void) {}
IMonitorModule				&IMonitorModule::operator=(IMonitorModule const&) {return (*this);}
