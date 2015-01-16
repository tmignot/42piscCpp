#include "LoopEnd.hpp"

LoopEnd::LoopEnd(void) : Instruction() {}
LoopEnd::~LoopEnd(void)
{
	if (this->next)
		delete this->next;
}

void			LoopEnd::execute(std::vector<char> &ptr, int &i)
{
	ptr = ptr;
	i = i;
}
