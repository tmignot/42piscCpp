#include "Mindopen.hpp"

Mindopen::Mindopen(void) : MEMSIZE(1000), ptr(std::vector<char>(this->MEMSIZE, 0)), currentIndex(0), instructions(NULL)
{
	this->allowedChars = new char[10];
	this->allowedChars[0] = 'a';
	this->allowedChars[1] = 'b';
	this->allowedChars[2] = 'c';
	this->allowedChars[3] = 'd';
	this->allowedChars[4] = 'e';
	this->allowedChars[5] = 'f';
	this->allowedChars[6] = 'g';
	this->allowedChars[7] = 'h';
	this->allowedChars[8] = ' ';
	this->allowedChars[9] = '\n';
}

bool				Mindopen::isAllowed(const char c)
{
	int			i = 0;

	while (i < 10)
	{
		if (this->allowedChars[i] == c)
			return (true);
		i++;
	}
	std::cout << "char not allowed : " << (int)c << std::endl;
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
	const char *stri = str.c_str();

	for(int i=0; stri[i]; i++)
	{
		char c = stri[i];
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
            case 'c':
				if (this->instructions)
				{
					this->instructions->last->next = new Increment();
					this->instructions->last = this->instructions->last->next;
				}
				else
					this->instructions = new Increment();
                break;

            case 'd':
				if (this->instructions)
				{
					this->instructions->last->next = new Decrement();
					this->instructions->last = this->instructions->last->next;
				}
				else
					this->instructions = new Decrement();
                break;

            case 'b':
				if (this->instructions)
				{
					this->instructions->last->next = new Forward();
					this->instructions->last = this->instructions->last->next;
				}
				else
					this->instructions = new Forward();
                break;

            case 'a':
				if (this->instructions)
				{
					this->instructions->last->next = new Backward();
					this->instructions->last = this->instructions->last->next;
				}
				else
					this->instructions = new Backward();
                break;

            case 'e':
				if (this->instructions)
				{
					this->instructions->last->next = new Output();
					this->instructions->last = this->instructions->last->next;
				}
				else
					this->instructions = new Output();
                break;

            case 'f':
				if (this->instructions)
				{
					this->instructions->last->next = new Input();
					this->instructions->last = this->instructions->last->next;
				}
				else
					this->instructions = new Input();
                break;

            case 'g':
				if (this->instructions)
				{
					this->instructions->last->next = new LoopStart();
					this->instructions->last = this->instructions->last->next;
				}
				else
					this->instructions = new LoopStart();
                break;

            case 'h':
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
