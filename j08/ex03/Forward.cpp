#include "Forward.hpp"

Forward::Forward(void) : Instruction() {}
Forward::~Forward(void)
{
	if (this->next)
		delete this->next;
}

void			Forward::execute(std::vector<char> &ptr, int &i)
{
	if (i == static_cast<int>(ptr.size()))
		i = 0;
	else
		i++;
	if (this->next)
		this->next->execute(ptr, i);
}
