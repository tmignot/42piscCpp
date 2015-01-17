#include "Hostname.hpp"

Hostname::Hostname(void) : IMonitorModule() {}
Hostname::Hostname(Hostname const &hostname) : IMonitorModule() {*this = hostname;}
Hostname::~Hostname(void) {}
Hostname				&Hostname::operator=(Hostname const&) {return (*this);}
