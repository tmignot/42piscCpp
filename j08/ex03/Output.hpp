#ifndef OUTPUT_H
# define OUTPUT_H

#include "Instruction.hpp"
#include <iostream>

class Output : public Instruction
{
	private:
		Output(Output const&);
		Output const			&operator=(Output const&);

	public:
		Output(void);
		virtual ~Output(void);
		virtual void			execute(std::vector<char>&, int&);
};

#endif
