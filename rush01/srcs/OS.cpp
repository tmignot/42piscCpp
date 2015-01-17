#include "OS.hpp"

OS::OS(void) : IMonitorModule() {}
OS::OS(OS const &os) : IMonitorModule() {*this = os;}
OS::~OS(void) {}
OS				&OS::operator=(OS const&) {return (*this);}
