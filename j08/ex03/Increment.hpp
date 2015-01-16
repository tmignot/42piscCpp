#ifndef INCREMENT_H
# define INCREMENT_H

#include "Instruction.hpp"

class Increment : public Instruction
{
	private:
		Increment(Increment const&);
		Increment const			&operator=(Increment const&);

	public:
		Increment(void);
		virtual ~Increment(void);
		virtual void			execute(std::vector<char>&, int&);
};

#endif
