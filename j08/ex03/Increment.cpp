#include "Increment.hpp"

Increment::Increment(void) : Instruction() {}
Increment::~Increment(void)
{
	if (this->next)
		delete this->next;
}

void			Increment::execute(std::vector<char> &ptr, int &i)
{
	ptr[i]++;
	if (this->next)
		this->next->execute(ptr, i);
}
