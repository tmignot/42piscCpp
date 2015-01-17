#include "Network.hpp"

Network::Network(void) : IMonitorModule() {}
Network::Network(Network const &network) : IMonitorModule() {*this = network;}
Network::~Network(void) {}
Network				&Network::operator=(Network const&) {return (*this);}
