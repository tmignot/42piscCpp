#ifndef TIME_HPP
# define TIME_HPP

#include "IMonitorModule.hpp"

class Time : public IMonitorModule
{
	private:
		char										type;
		std::vector<std::string>					data;
		int											getWidth(void) const;
	protected:
	public:
		Time(void);
		Time(Time const&);
		~Time(void);
		Time										&operator=(Time const&);
		virtual void								update(void);
		virtual std::vector<std::string> const		&getData(void) const;
		virtual WINDOW								*initWindow(WINDOW*, WINDOW*) const;
		virtual char								getType(void) const;
};

#endif
