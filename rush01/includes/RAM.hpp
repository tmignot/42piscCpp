#ifndef RAM_HPP
# define RAM_HPP

#include "IMonitorModule.hpp"

class RAM : public IMonitorModule
{
	private:
	protected:
	public:
		RAM(void);
		RAM(RAM const&);
		~RAM(void);
		RAM			&operator=(RAM const&);
};

#endif
