#ifndef DECREMENT_H
# define DECREMENT_H

#include "Instruction.hpp"

class Decrement : public Instruction
{
	private:
		Decrement(Decrement const&);
		Decrement const			&operator=(Decrement const&);

	public:
		Decrement(void);
		virtual ~Decrement(void);
		virtual void			execute(std::vector<char>&, int&);
};

#endif
