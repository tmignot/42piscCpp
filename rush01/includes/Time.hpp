#ifndef TIME_HPP
# define TIME_HPP

#include "IMonitorModule.hpp"
#include <sys/time.h>
#include <sstream>

class Time : public IMonitorModule
{
	private:
		char										type;
		std::vector<std::string>					data;
		std::string									name;
	protected:
	public:
		Time(void);
		Time(Time const&);
		~Time(void);
		Time										&operator=(Time const&);
		virtual void								update(void);
		virtual std::vector<std::string> const		&getData(void) const;
		virtual char								getType(void) const;
		virtual std::string const					&getName(void) const;
};

#endif
