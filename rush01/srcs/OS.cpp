#include "OS.hpp"

OS::OS(void) : IMonitorModule(), type('i'), data(std::vector<std::string>()), name("OS")
{
	this->update();
}
OS::OS(OS const &os) : IMonitorModule() {*this = os;}
OS::~OS(void) {}
OS								&OS::operator=(OS const&) {return (*this);}
char							OS::getType(void) const
{
	return (this->type);
}
std::vector<std::string> const	&OS::getData(void) const
{
	return (this->data);
}
void							OS::update(void)
{
	char os[256];
	char type[256];
	size_t len = sizeof(os);

	data.clear();
	sysctlbyname("kern.ostype", &os, &len, NULL, 0);
	sysctlbyname("kern.osrelease", &type, &len, NULL, 0);
	data.push_back(std::string("OS type: ") + std::string(os));
	data.push_back(std::string("OS Release: ") + std::string(type));
}

std::string const						&OS::getName(void) const
{
	return (this->name);
}
