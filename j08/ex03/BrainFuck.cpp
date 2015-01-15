#include "BrainFuck.hpp"

BrainFuck::BrainFuck(void) : MEMSIZE(1000), ptr(std::vector<char>(this->MEMSIZE, 0)), currentIndex(0)
{
	this->allowedChars = new char[9];
	this->allowedChars[0] = '>';
	this->allowedChars[1] = '<';
	this->allowedChars[2] = '+';
	this->allowedChars[3] = '-';
	this->allowedChars[4] = '[';
	this->allowedChars[5] = ']';
	this->allowedChars[6] = '.';
	this->allowedChars[7] = ',';
	this->allowedChars[8] = ' ';
}

bool BrainFuck::isAllowed(const char c)
{
	int			i = 0;

	while (i < 9)
	{
		if (this->allowedChars[i] == c)
			return (true);
		i++;
	}
	return (false);
}

BrainFuck::~BrainFuck(void) {}

bool BrainFuck::IsCorrect(std::string str)
{
    int loopLevel = 0;

	for(std::string::iterator it = str.begin(); it != str.end(); it++)
	{
		char c = *it;
        if (!this->isAllowed(c))
            return false;
        if (c == '[')
            loopLevel++;
        if (c == ']')
            loopLevel--;
	}

    return (loopLevel == 0 ? true : false);
}

void BrainFuck::ResetMem(void)
{
    for (int i = 0; i < this->MEMSIZE; i++)
        this->ptr[i] = 0;
    this->currentIndex = 0;
}

void BrainFuck::Parse(std::string code, int id)
{
    int loopDepth = 0;
    for (unsigned int i = 0; i < code.length(); i++)
    {
        switch (code.c_str()[i])
        {
            case '+':
                this->ptr[currentIndex]++;
                break;

            case '-':
                this->ptr[currentIndex]--;
                break;

            case '>':
                if (this->currentIndex == this->MEMSIZE - 1)
                    this->currentIndex = 0;
                this->currentIndex++;
                break;

            case '<':
                if (this->currentIndex == 0)
                    this->currentIndex = this->MEMSIZE;
                this->currentIndex--;
                break;

            case '.':
                std::cout << this->ptr[this->currentIndex];
                break;

            case ',':
            	this->ptr[this->currentIndex] = static_cast<char>(getchar());
                break;

            case '[':
                loopDepth++;
                this->Parse(code.substr(i + 1, code.length() - i), this->currentIndex);
                while(loopDepth != 0)
                {
                    char c = const_cast<char*>(code.c_str())[++i];
                    if (c == '[')
                        loopDepth++;
                    if (c == ']')
                        loopDepth--;
                }
                break;

            case ']':
                if (this->ptr[id] == 0)
                    return;
                i = -1;
                break;
        }
    }
}

void BrainFuck::Parse(std::string code)
{
    this->Parse(code, 0);
}

std::string			toLower(std::string str)
{
	std::string		ret("");

	for(std::string::iterator it = str.begin(); it != str.end(); it++)
	{
		char c = *it;
		if (c >= 'A' && c <= 'Z')
			ret += c - ('A' - 'a');
		else
			ret += c;
	}
	return (ret);
}

void BrainFuck::ToDo(std::string code) 
{
    if (this->IsCorrect(code))
    {
        this->Parse(code);
    }
}