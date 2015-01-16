#ifndef INPUT_H
# define INPUT_H

#include "Instruction.hpp"
#include <iostream>

class Input : public Instruction
{
	private:
		Input(Input const&);
		Input const			&operator=(Input const&);

	public:
		Input(void);
		virtual ~Input(void);
		virtual void			execute(std::vector<char>&, int&);
};

#endif
