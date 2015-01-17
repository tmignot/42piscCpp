#include "ShellDisplay.hpp"

ShellDisplay::ShellDisplay(void) : IMonitorDisplay() {}
ShellDisplay::ShellDisplay(ShellDisplay const &shell) : IMonitorDisplay() {*this = shell;}
ShellDisplay::~ShellDisplay(void) {}
ShellDisplay				&ShellDisplay::operator=(ShellDisplay const&) {return (*this);}
