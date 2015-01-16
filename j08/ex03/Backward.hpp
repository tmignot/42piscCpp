#ifndef BACKWARD_H
# define BACKWARD_H

#include "Instruction.hpp"

class Backward : public Instruction
{
	private:
		Backward(Backward const&);
		Backward const			&operator=(Backward const&);

	public:
		Backward(void);
		virtual ~Backward(void);
		virtual void			execute(std::vector<char>&, int&);
};

#endif
