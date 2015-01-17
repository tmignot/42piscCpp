#include "CPU.hpp"

CPU::CPU(void) : IMonitorModule() {}
CPU::CPU(CPU const &cpu) : IMonitorModule() {*this = cpu;}
CPU::~CPU(void) {}
CPU				&CPU::operator=(CPU const&) {return (*this);}
