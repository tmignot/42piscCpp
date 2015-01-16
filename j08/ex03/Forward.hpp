#ifndef FORWARD_H
# define FORWARD_H

#include "Instruction.hpp"

class Forward : public Instruction
{
	private:
		Forward(Forward const&);
		Forward const			&operator=(Forward const&);

	public:
		Forward(void);
		virtual ~Forward(void);
		virtual void			execute(std::vector<char>&, int&);
};

#endif
