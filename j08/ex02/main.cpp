#include <iostream>
#include <algorithm>
#include <list>
#include "mutantstack.hpp"

int main(void)
{
	Mutantstack<int> stack;

	stack.push(12);
	stack.push(-12);
	stack.push(42);

	unsigned int index = stack.size();

	for (unsigned int i = 0; i < index; i++)
	{
	    std::cout << "Sparta elem " << i << ": " << "  "  << stack.top() << std::endl;
	    stack.pop();
	}

	return 0;
}