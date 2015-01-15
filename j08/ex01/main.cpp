#include "Span.hpp"
#include <iostream>

int main() {
	
	Span s(10000);

	try {
		s.addRange(1, 9999);
		s.addNumber(100000);
		std::cout << s.longestSpan() << std::endl;
		std::cout << s.shortestSpan() << std::endl;
		s.addNumber(234);
	
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}


	return 0;

}
