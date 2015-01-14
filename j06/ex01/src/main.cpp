#include "Data.hpp"

void dumpData(Data* d)
{
	std::cout << "dump:" << std::endl;
	std::cout << "d: " << d->s1 << std::endl;
	std::cout << "d: " << d->s2 << std::endl;
	std::cout << "n: " << d->n << std::endl;
}

int main()
{
	srand (time(NULL));

	void* s = serialize();
	Data* d = deserialize(s);
	dumpData(d);
	Data sd;
	sd.s1 = "11111111";
	sd.s2 = "2222";
	sd.n = 9;
	dumpData(&sd);
	return 0;
}
