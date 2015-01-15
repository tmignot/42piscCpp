#include "easyfind.hpp"

int		main( void ) {
	std::vector<int>	pouet;
	std::list<int>		pouet2;

	pouet.push_back(45);
	pouet.push_back(40);
	pouet.push_back(35);
	pouet.push_back(30);
	pouet2.push_back(45);
	pouet2.push_back(42);
	pouet2.push_back(40);
	pouet2.push_back(35);

	try {
		easyfind< std::vector <int> >(pouet, 25);
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	try {
		easyfind< std::list <int> >(pouet2, 25);
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	try {
		easyfind< std::vector <int> >(pouet, 35);
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	try {
		easyfind< std::list <int> >(pouet2, 35);
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	return (0);
}