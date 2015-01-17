#ifndef CPU_HPP
# define CPU_HPP

#include "IMonitorModule.hpp"

class CPU : public IMonitorModule
{
	private:
		char								type;
		std::vector<std::string>			data;
	protected:
	public:
		CPU(void);
		CPU(CPU const&);
		~CPU(void);
		CPU									&operator=(CPU const&);
		virtual void						update(void);
		virtual std::vector<std::string>	getData(void);
};

#endif
