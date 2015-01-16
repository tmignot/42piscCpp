#ifndef LOOP_END_H
# define LOOP_END_H

#include "Instruction.hpp"

class LoopEnd : public Instruction
{
	private:
		LoopEnd(LoopEnd const&);
		LoopEnd const			&operator=(LoopEnd const&);

	public:
		LoopEnd(void);
		virtual ~LoopEnd(void);
		virtual void			execute(std::vector<char>&, int&);
};

#endif
