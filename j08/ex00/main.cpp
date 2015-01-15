#include <vector>
#include <list>
#include <iostream>
#include "easyfind.hpp"

int		main() {
	std::cout << "IN VECTOR" << std::endl;
	{
		std::vector<int> v;
		for (int i = 0; i < 20; ++i) {
			v.push_back(i);
		}
		if (easyfind<std::vector<int> >(v, 4))
			std::cout << "4 was found" << std::endl;
		else
			std::cout << "4 was not found" << std::endl;

		if (easyfind<std::vector<int> >(v, 42))
			std::cout << "42 was found" << std::endl;
		else
			std::cout << "42 was not found" << std::endl;
		std::cout << std::endl;
	}

	std::cout << "IN LIST" << std::endl;
	{
		std::list<int> l;
		for (int i = 0; i < 20; ++i) {
			l.push_back(i);
		}
		if (easyfind<std::list<int> >(l, 4))
			std::cout << "4 was found" << std::endl;
		else
			std::cout << "4 was not found" << std::endl;

		if (easyfind<std::list<int> >(l, 42))
			std::cout << "42 was found" << std::endl;
		else
			std::cout << "42 was not found" << std::endl;
		std::cout << std::endl;
	}

	return 0;
}
