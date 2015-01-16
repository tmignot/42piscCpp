#ifndef INSTRUCTION_H
# define INSTRUCTION_H

#include <vector>
#include <cstdlib>
#include <iostream>

class Instruction
{
	private:
		Instruction(Instruction const&);
		Instruction const			&operator=(Instruction const&);

	public:
		Instruction					*last;
		Instruction					*next;
		Instruction(void);
		virtual ~Instruction(void);
		virtual void				execute(std::vector<char>&, int&)=0;
};

#endif
