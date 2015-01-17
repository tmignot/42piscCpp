#ifndef CPU_HPP
# define CPU_HPP

#include "IMonitorModule.hpp"

class CPU : public IMonitorModule
{
	private:
		char										type;
		std::vector<std::string>					data;
		int											getWidth(void) const;
	protected:
	public:
		CPU(void);
		CPU(CPU const&);
		~CPU(void);
		CPU											&operator=(CPU const&);
		virtual void								update(void);
		virtual std::vector<std::string> const		&getData(void) const;
		virtual char								getType(void) const;
		virtual WINDOW								*initWindow(WINDOW*, WINDOW*) const;
};

#endif
