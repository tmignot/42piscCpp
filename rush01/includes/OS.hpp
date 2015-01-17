#ifndef OS_HPP
# define OS_HPP

#include "IMonitorModule.hpp"

class OS : public IMonitorModule
{
	private:
		char										type;
		std::vector<std::string>					data;
		int											getWidth(void) const;
	protected:
	public:
		OS(void);
		OS(OS const&);
		~OS(void);
		OS											&operator=(OS const&);
		virtual void								update(void) const;
		virtual std::vector<std::string> const		&getData(void) const;
		virtual char								getType(void) const;
		virtual WINDOW								*initWindow(WINDOW*, WINDOW*) const;
};

#endif
