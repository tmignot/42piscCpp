#ifndef SPAN_HPP
 #define SPAN_HPP
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <stdlib.h>
#include "Span.hpp"

class Span {

public: 

	Span( void );
	Span( int N );
	Span( Span const & src );
	~Span( void );

	Span &	operator=( Span const & rhs );

	void			addNumber( int val );
	void			addRange( int begin, int end );
	unsigned int	shortestSpan();
	unsigned int	longestSpan();


private:
	std::vector<unsigned int>	_vector;
	unsigned int				_maxItems;
	unsigned int				_currentIndex;

}; 

class spanLimitReached : public std::exception {
	virtual const char* what() const throw() {
		return ("Limit reached for this Span Container");
	}
};

class notEnoughValues : public std::exception {
	virtual const char* what() const throw() {
		return ("Not enough values in the span container");
	}
};

std::ostream &	operator<<( std::ostream & o, Span const & i );

#endif /* SPAN_HPP */
