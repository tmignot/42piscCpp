#include "Backward.hpp"

Backward::Backward(void) : Instruction() {}
Backward::~Backward(void)
{
	if (this->next)
		delete this->next;
}

void			Backward::execute(std::vector<char> &ptr, int &i)
{
	if (i == 0)
		i = static_cast<int>(ptr.size());
	i--;
	if (this->next)
		this->next->execute(ptr, i);
}
