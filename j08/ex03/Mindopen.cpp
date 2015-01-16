#include "Mindopen.hpp"

Mindopen::Mindopen(void) : MEMSIZE(1000), ptr(std::vector<char>(this->MEMSIZE, 0)), currentIndex(0), instructions(NULL)
{
	this->allowedChars = new char[9];
	this->allowedChars[0] = '>';
	this->allowedChars[1] = '<';
	this->allowedChars[2] = '+';
	this->allowedChars[3] = '-';
	this->allowedChars[4] = '.';
	this->allowedChars[5] = ',';
	this->allowedChars[6] = '[';
	this->allowedChars[7] = ']';
	this->allowedChars[8] = ' ';
}

bool				Mindopen::isAllowed(const char c)
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

Mindopen::~Mindopen(void)
{
	if (this->instructions)
		delete this->instructions;
}

bool				Mindopen::IsCorrect(std::string str)
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

void				Mindopen::ResetMem(void)
{
    for (int i = 0; i < this->MEMSIZE; i++)
        this->ptr[i] = 0;
    this->currentIndex = 0;
}

void				Mindopen::Parse(std::string code)
{
    for (unsigned int i = 0; i < code.length(); i++)
    {
        switch (code.c_str()[i])
        {
            case '+':
				if (this->instructions)
				{
					this->instructions->last->next = new Increment();
					this->instructions->last = this->instructions->last->next;
				}
				else
					this->instructions = new Increment();
                break;

            case '-':
				if (this->instructions)
				{
					this->instructions->last->next = new Decrement();
					this->instructions->last = this->instructions->last->next;
				}
				else
					this->instructions = new Decrement();
                break;

            case '>':
				if (this->instructions)
				{
					this->instructions->last->next = new Forward();
					this->instructions->last = this->instructions->last->next;
				}
				else
					this->instructions = new Forward();
                break;

            case '<':
				if (this->instructions)
				{
					this->instructions->last->next = new Backward();
					this->instructions->last = this->instructions->last->next;
				}
				else
					this->instructions = new Backward();
                break;

            case '.':
				if (this->instructions)
				{
					this->instructions->last->next = new Output();
					this->instructions->last = this->instructions->last->next;
				}
				else
					this->instructions = new Output();
                break;

            case ',':
				if (this->instructions)
				{
					this->instructions->last->next = new Input();
					this->instructions->last = this->instructions->last->next;
				}
				else
					this->instructions = new Input();
                break;

            case '[':
				if (this->instructions)
				{
					this->instructions->last->next = new LoopStart();
					this->instructions->last = this->instructions->last->next;
				}
				else
					this->instructions = new LoopStart();
                break;

            case ']':
				if (this->instructions)
				{
					this->instructions->last->next = new LoopEnd();
					this->instructions->last = this->instructions->last->next;
				}
				else
					this->instructions = new LoopEnd();
                break;
        }
    }
}

void				Mindopen::ToDo(std::string code) 
{
    if (this->IsCorrect(code))
    {
        this->Parse(code);
    }
}

void				Mindopen::execute(void)
{
	this->currentIndex = 0;
	if (this->instructions)
		this->instructions->execute(this->ptr, this->currentIndex);
}
