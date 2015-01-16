#ifndef LOOP_START_H
# define LOOP_START_H

#include "Instruction.hpp"
#include <typeinfo>
#include "LoopEnd.hpp"
#include <exception>

class LoopStart : public Instruction
{
	private:
		LoopStart(LoopStart const&);
		LoopStart const			&operator=(LoopStart const&);

	public:
		LoopStart(void);
		virtual ~LoopStart(void);
		virtual void			execute(std::vector<char>&, int&);
};

#endif
