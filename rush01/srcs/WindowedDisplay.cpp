#include "WindowedDisplay.hpp"

WindowedDisplay::WindowedDisplay(void) : IMonitorDisplay(), name("FUCK YOU") {}
WindowedDisplay::WindowedDisplay(WindowedDisplay const &windowed) : IMonitorDisplay() {*this = windowed;}
WindowedDisplay::~WindowedDisplay(void) {}
WindowedDisplay				&WindowedDisplay::operator=(WindowedDisplay const&) {return (*this);}
void						WindowedDisplay::draw(void) const {}
void						WindowedDisplay::addModule(char code) {(void)code;}
std::string const			&WindowedDisplay::parseCommand(char) {return (this->name);}
