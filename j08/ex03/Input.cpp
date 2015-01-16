#include "Input.hpp"

Input::Input(void) : Instruction() {}
Input::~Input(void)
{
	if (this->next)
		delete this->next;
}

void			Input::execute(std::vector<char> &ptr, int &i)
{
	ptr[i] = static_cast<char>(getchar());
	if (this->next)
		this->next->execute(ptr, i);
}
