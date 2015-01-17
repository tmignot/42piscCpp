#include "Time.hpp"

Time::Time(void) : IMonitorModule() {}
Time::Time(Time const &time) : IMonitorModule() {*this = time;}
Time::~Time(void) {}
Time				&Time::operator=(Time const&) {return (*this);}
