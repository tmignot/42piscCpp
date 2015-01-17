#include "WindowedDisplay.hpp"

WindowedDisplay::WindowedDisplay(void) : IMonitorDisplay() {}
WindowedDisplay::WindowedDisplay(WindowedDisplay const &windowed) : IMonitorDisplay() {*this = windowed;}
WindowedDisplay::~WindowedDisplay(void) {}
WindowedDisplay				&WindowedDisplay::operator=(WindowedDisplay const&) {return (*this);}
void						WindowedDisplay::draw(void) {}
void						WindowedDisplay::addModule(Module&) {}
