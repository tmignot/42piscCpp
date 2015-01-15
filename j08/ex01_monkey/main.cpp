#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include "Span.hpp"


int main( void ) {
	Span	values(900);
	Span	values2(10);
	Span	valuesTooMany(2);
	Span	valuesNotEnough(3);

	values.addRange (1101, 2000);

	values2.addNumber(8);
	values2.addNumber(100);


	std::cout << values.shortestSpan() << std::endl;
	std::cout << values.longestSpan() << std::endl;

	std::cout << values2.shortestSpan() << std::endl;
	std::cout << values2.longestSpan() << std::endl;

	valuesTooMany.addNumber(1);
	valuesTooMany.addNumber(2);
	//valuesTooMany.addNumber(3); // uncomment to get an error thrown

	valuesNotEnough.addNumber(1);
	//std::cout << valuesNotEnough.shortestSpan() << std::endl; // uncomment to get an error thrown

	return (0);
}