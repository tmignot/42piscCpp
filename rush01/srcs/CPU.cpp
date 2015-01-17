#include "CPU.hpp"

CPU::CPU(void) : IMonitorModule() {}
CPU::CPU(CPU const &cpu) : IMonitorModule(static_cast<IMonitorModule>(cpu)) {*this = cpu;}
CPU::~CPU(void) {}
CPU				&CPU::operator=(CPU const&) {return (*this);}
