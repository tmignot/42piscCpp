#ifndef DATA_HEADER
#define DATA_HEADER

#include <iostream>
#include <sstream>
#include <cstdlib>
#include <ctime>

struct Data
{
	std::string	s1;
	int			n;
	std::string	s2;
};

Data* deserialize(void * raw);
void* serialize(void);

#endif /*DATA_HEADER*/
