#include "Array.hpp"
#include <string>
#include <iostream>

int					main(void)
{
	Array<int>				intArray(10);
	Array<std::string>		stringArray(11);

	for (unsigned int i = 0; i < intArray.size(); i++)
		intArray[i] = i;
	std::cout << "Array<int>" << std::endl;
	for (unsigned int i = 0; i < intArray.size(); i++)
		std::cout << intArray[i] << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	stringArray[0] = "this";
	stringArray[1] = "is";
	stringArray[2] = "a";
	stringArray[3] = "long";
	stringArray[4] = "fucking";
	stringArray[5] = "string";
	stringArray[6] = "array";
	stringArray[7] = "does";
	stringArray[8] = "this";
	stringArray[9] = "never";
	stringArray[10] = "end ?";

	std::cout << "Array<std::string>" << std::endl;
	for (unsigned int i = 0; i < stringArray.size(); i++)
		std::cout << stringArray[i] << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	Array<std::string>		copyStringArray(stringArray);

	std::cout << "Array<std::string> copy" << std::endl;
	for (unsigned int i = 0; i < copyStringArray.size(); i++)
		std::cout << copyStringArray[i] << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	stringArray[3] = std::string("short");

	std::cout << "Array<std::string> Modified" << std::endl;
	for (unsigned int i = 0; i < stringArray.size(); i++)
		std::cout << stringArray[i] << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "Array<std::string> original copy" << std::endl;
	for (unsigned int i = 0; i < copyStringArray.size(); i++)
		std::cout << copyStringArray[i] << std::endl;
	return (0);
}
