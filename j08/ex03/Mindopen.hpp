#include <string>
#include <iostream>
#include <cstdio>
#include <vector>

class Mindopen
{
    private:
        char                *allowedChars;
        const int           MEMSIZE;
        std::vector<char>     ptr;
        int                 currentIndex;
		Mindopen(Mindopen const&);
		Mindopen&		operator=(Mindopen const&);

    public:
        Mindopen(void);
        ~Mindopen(void);

        bool			isAllowed(const char c);

        bool			IsCorrect(std::string str);

        void			ResetMem(void);

        void			Parse(std::string code, int id);

        void			Parse(std::string code);

        void			ToDo(std::string str);
};
