#include "Decrement.hpp"

Decrement::Decrement(void) : Instruction() {}
Decrement::~Decrement(void)
{
	if (this->next)
		delete this->next;
}

void			Decrement::execute(std::vector<char> &ptr, int &i)
{
	ptr[i]--;
	if (this->next)
		this->next->execute(ptr, i);
}
