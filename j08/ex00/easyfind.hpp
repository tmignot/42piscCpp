#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <exception>
#include <algorithm>

template<class T>
bool	easyfind(T const& container, int i) {
	try {
		if (std::find(container.begin(), container.end(), i) != container.end())
			return true;
		return false;
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
		return false;
	}
}

#endif
