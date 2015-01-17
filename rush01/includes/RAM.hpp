#ifndef RAM_HPP
# define RAM_HPP

#include "IMonitorModule.hpp"

class RAM : public IMonitorModule
{
	private:
		char										type;
		std::vector<std::string>					data;
		int											getWidth(void) const;
	protected:
	public:
		RAM(void);
		RAM(RAM const&);
		~RAM(void);
		RAM											&operator=(RAM const&);
		virtual void								update(void) const;
		virtual std::vector<std::string> const		&getData(void) const;
		virtual char								getType(void) const;
		virtual WINDOW								*initWindow(WINDOW*, WINDOW*) const; 
};

#endif
