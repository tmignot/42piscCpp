#include "Output.hpp"

Output::Output(void) : Instruction() {}
Output::~Output(void)
{
	if (this->next)
		delete this->next;
}

void			Output::execute(std::vector<char> &ptr, int &i)
{
	std::cout << ptr[i];
	if (this->next)
		this->next->execute(ptr, i);
}
