#ifndef TIME_HPP
# define TIME_HPP

#include "IMonitorModule.hpp"

class Time : public IMonitorModule
{
	private:
	protected:
	public:
		Time(void);
		Time(Time const&);
		~Time(void);
		Time			&operator=(Time const&);
};

#endif
