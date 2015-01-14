#ifndef A_HEADER
#define A_HEADER

#include <iostream>
#include <sstream>
#include "Base.hpp"

class A : public Base
{
public:
	//constructors
	A();
	A(A const &);
	virtual ~A();

	//getters setters

	//other functions
	std::string	toString()const;

	A&	operator=(A const &);

protected:
};

std::ostream	&operator<<(std::ostream &o, A const &i);

#endif /*A_HEADER*/
