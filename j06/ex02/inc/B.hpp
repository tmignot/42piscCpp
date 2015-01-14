#ifndef B_HEADER
#define B_HEADER

#include <iostream>
#include <sstream>
#include "Base.hpp"

class B : public Base
{
public:
	//constructors
	B();
	B(B const &);
	virtual ~B();

	//getters setters

	//other functions
	std::string	toString()const;

	B&	operator=(B const &);

protected:
};

std::ostream	&operator<<(std::ostream &o, B const &i);

#endif /*B_HEADER*/
