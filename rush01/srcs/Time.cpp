#include "Time.hpp"

Time::Time(void) : IMonitorModule() {}
Time::Time(Time const &time) : IMonitorModule(static_cast<IMonitorModule>(time)) {*this = time;}
Time::~Time(void) {}
Time				&Time::operator=(Time const&) {return (*this);}
