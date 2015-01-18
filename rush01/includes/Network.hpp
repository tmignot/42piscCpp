#ifndef NETWORK_HPP
# define NETWORK_HPP

#include "IMonitorModule.hpp"
#include <net/route.h>
#include <net/if.h>
#include <sys/sysctl.h>
#include <sstream>

class Network : public IMonitorModule
{
	private:
		char									type;
		std::vector<std::string>				data;
		std::string								name;
	protected:
	public:
		Network(void);
		Network(Network const&);
		~Network(void);
		Network										&operator=(Network const&);
		virtual void								update(void);
		virtual std::vector<std::string> const		&getData(void) const;
		virtual char								getType(void) const;
		virtual std::string const					&getName(void) const;
};

#endif
