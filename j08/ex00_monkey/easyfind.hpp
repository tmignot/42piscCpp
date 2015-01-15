#ifndef EASYFIND_HPP
 #define EASYFIND_HPP
 #include <iostream>
 #include <vector>
 #include <algorithm>
 #include <list>

class notFound : public std::exception {
	virtual const char* what() const throw() {
		return ("Value not found");
	}
};

template< typename T >
void easyfind (T const array, int value ) {
	if (std::find(array.begin(), array.end(), value) != array.end() ) {
		std::cout << "Value found" << std::endl;
	} else {
		throw notFound();
	}
}

#endif
