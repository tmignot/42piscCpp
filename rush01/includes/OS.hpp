#ifndef OS_HPP
# define OS_HPP

#include "IMonitorModule.hpp"

class OS : public IMonitorModule
{
	private:
	protected:
	public:
		OS(void);
		OS(OS const&);
		~OS(void);
		OS			&operator=(OS const&);
};

#endif
