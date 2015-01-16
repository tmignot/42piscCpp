#include "LoopStart.hpp"

LoopStart::LoopStart(void) : Instruction() {}
LoopStart::~LoopStart(void)
{
	if (this->next)
		delete this->next;
}

void			LoopStart::execute(std::vector<char> &ptr, int &i)
{
	Instruction			*tmp = this->next;
	int					loopDepth = 1;
	int					tmpPos = i;
	
	while (ptr[i])
		this->next->execute(ptr, i);
	i = tmpPos;
	while (loopDepth != 0)
	{
		try
		{
			LoopStart	*tmp2 = dynamic_cast<LoopStart*>(tmp);
			if (tmp2)
				loopDepth++;
			else
			{
				try
				{
					LoopEnd		*tmp3 = dynamic_cast<LoopEnd*>(tmp);
					if (tmp3)
						loopDepth--;
				}
				catch (std::exception e)
				{}
			}
		}
		catch (std::exception e)
		{}
		tmp = tmp->next;
	}
	if (tmp)
		tmp->execute(ptr, i);
}
