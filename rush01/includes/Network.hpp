#ifndef NETWORK_HPP
# define NETWORK_HPP

#include "IMonitorModule.hpp"

class Network : public IMonitorModule
{
	private:
	protected:
	public:
		Network(void);
		Network(Network const&);
		~Network(void);
		Network			&operator=(Network const&);
};

#endif
