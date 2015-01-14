#include "Data.hpp"

Data* deserialize(void *raw)
{
	return reinterpret_cast<Data*>(raw);
}

std::string randomStr()
{
	std::string str;
	for (int i = 0; i < 8; ++i){
		char c = static_cast<char>(rand() % 100 + 32);
		str += c;
	}
	return str;
}

void* serialize(void)
{
	Data* s = new Data();
	s->s1 = randomStr();
	s->s2 = randomStr();
	s->n = rand();
	return s;
}

