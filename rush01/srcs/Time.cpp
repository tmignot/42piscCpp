#include "Time.hpp"

Time::Time(void) : IMonitorModule(), type('i'), data(std::vector<std::string>()), name("Time")
{
	this->update();
}
Time::Time(Time const &time) : IMonitorModule() {*this = time;}
Time::~Time(void) {}
Time				&Time::operator=(Time const&) {return (*this);}
char							Time::getType(void) const
{
	return (this->type);
}
std::vector<std::string> const	&Time::getData(void) const
{
	return (this->data);
}
void							Time::update(void)
{
	time_t t = time(0);
	struct tm * now = localtime( & t );
	data.clear();
	data.push_back("  Hello 42 !  ");
	std::ostringstream date;
  	date<< now->tm_mday << '/'
		<< (now->tm_mon + 1) << '/'
		<< (now->tm_year + 1900);
	data.push_back(date.str());
	date.str("");
	date<< (now->tm_hour) << 'h'
		<< now->tm_min << 'm'
		<< now->tm_sec << 's';
	data.push_back(date.str());
}

std::string const				&Time::getName(void) const
{
	return (this->name);
}
