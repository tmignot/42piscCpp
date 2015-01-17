#include "IMonitorDisplay.hpp"

IMonitorDisplay::IMonitorDisplay(void) {}
IMonitorDisplay::IMonitorDisplay(IMonitorDisplay const &display) {*this = display;}
IMonitorDisplay::~IMonitorDisplay(void) {}
IMonitorDisplay				&IMonitorDisplay::operator=(IMonitorDisplay const&) {return (*this);}
