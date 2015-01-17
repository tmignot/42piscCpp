#include "RAM.hpp"

RAM::RAM(void) : IMonitorModule() {}
RAM::RAM(RAM const &ram) : IMonitorModule() {*this = ram;}
RAM::getData() {
	struct sysinfo	i;
	if (sysinfo(&i))
		return ;
	std::stringstream temp;
	temp << "total ram: " << i.totalram << std::endl;
	_totalram = temp;
	temp.clear();
	temp << "free ram: " << i.freeram << std::endl;
	_freeram = temp;
	temp.clear();
	std::cout << "shared ram: " << i.sharedram << std::endl;
	_sharedram = temp;
	temp.clear();
	std::cout << "buffer ram: " << i.bufferram << std::endl;
	_bufferram = temp;
	temp.clear();
	std::cout << "total swap: " << i.totalswap << std::endl;
	_totalswap = temp;
	temp.clear();
	std::cout << "free swap: " << i.freeswap << std::endl;
	_freeswap = temp;
	temp.clear();
	std::cout << "process: " << i.procs << std::endl;
	_process = temp;
	temp.clear();
}
RAM::~RAM(void) {}
RAM				&RAM::operator=(RAM const&) {return (*this);}
