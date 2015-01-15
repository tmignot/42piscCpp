#include "easyfind.hpp"
#include <iostream> 
#include <vector> 
#include <list> 

int main() {
	std::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(6);
	v.push_back(7);
	v.push_back(8);
	std::cout << ::easyfind(v, 2) << std::endl;
	std::cout << ::easyfind(v, 0) << std::endl;

		std::list<int> l;
		for (int i = 0; i < 20; ++i) {
			l.push_back(i);
		}
		std::cout << easyfind(l, 2) << std::endl;
		std::cout << easyfind(l, 542) << std::endl;
	return 9;
}
