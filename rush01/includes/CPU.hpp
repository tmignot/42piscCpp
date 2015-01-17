#ifndef CPU_HPP
# define CPU_HPP

#include "IMonitorModule.hpp"

class CPU : public IMonitorModule
{
	private:
	protected:
	public:
		CPU(void);
		CPU(CPU const&);
		~CPU(void);
		CPU			&operator=(CPU const&);
};

#endif
