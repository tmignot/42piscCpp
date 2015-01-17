#include "TUI_Display.hpp"

TUI_Display::TUI_Display(void) {}
TUI_Display::TUI_Display(TUI_Display const &display) {*this = display;}
TUI_Display::~TUI_Display(void) {}
TUI_Display				&TUI_Display::operator=(TUI_Display const&) {return (*this);}
