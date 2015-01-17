#include "RAM.hpp"

RAM::RAM(void) : IMonitorModule() {}
RAM::RAM(RAM const &ram) : IMonitorModule(static_cast<IMonitorModule>(ram)) {*this = ram;}
RAM::~RAM(void) {}
RAM				&RAM::operator=(RAM const&) {return (*this);}
