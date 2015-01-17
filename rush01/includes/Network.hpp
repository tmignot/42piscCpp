#ifndef NETWORK_HPP
# define NETWORK_HPP

#include "IMonitorModule.hpp"

class Network : public IMonitorModule
{
	private:
		char								type;
		std::vector<std::string>			data;
	protected:
	public:
		Network(void);
		Network(Network const&);
		~Network(void);
		Network								&operator=(Network const&);
		virtual void						update(void) const;
		virtual std::vector<std::string>	getData(void) const;
};

#endif
