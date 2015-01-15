#include <string>
#include <iostream>
#include <cstdio>
#include <vector>

class BrainFuck
{
    private:
        char                *allowedChars;
        const int           MEMSIZE;
        std::vector<char>     ptr;
        int                 currentIndex;

    public:
        BrainFuck(void);
        ~BrainFuck(void);

        bool isAllowed(const char c);

        bool IsCorrect(std::string str);

        void ResetMem(void);

        void Parse(std::string code, int id);

        void Parse(std::string code);

        void ToDo(std::string str);
};