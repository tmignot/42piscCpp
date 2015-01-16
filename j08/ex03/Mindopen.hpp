#ifndef MIND_OPEN_H
# define MIND_OPEN_H

#include <string>
#include <iostream>
#include <cstdio>
#include <vector>
#include "Instruction.hpp"
#include "Increment.hpp"
#include "Decrement.hpp"
#include "Forward.hpp"
#include "Backward.hpp"
#include "Output.hpp"
#include "Input.hpp"
#include "LoopStart.hpp"
#include "LoopEnd.hpp"

class Mindopen
{
    private:
        char				*allowedChars;
        const int			MEMSIZE;
        std::vector<char>	ptr;
        int					currentIndex;
		Mindopen(Mindopen const&);
		Mindopen&			operator=(Mindopen const&);
		Instruction			*instructions;

    public:
        Mindopen(void);
        ~Mindopen(void);

        bool			isAllowed(const char c);

        bool			IsCorrect(std::string str);

        void			ResetMem(void);

        void			Parse(std::string code);

        void			ToDo(std::string str);

		void			execute(void);
};

#endif
