#ifndef C_HEADER
#define C_HEADER

#include <iostream>
#include <sstream>

#include "Base.hpp"

class C : public Base
{
public:
	//constructors
	C();
	C(C const &);
	virtual ~C();

	//getters setters

	//other functions
	std::string	toString()const;

	C&	operator=(C const &);

protected:
};

std::ostream	&operator<<(std::ostream &o, C const &i);

#endif /*C_HEADER*/
