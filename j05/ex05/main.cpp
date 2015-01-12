#include "CentralBureaucracy.hpp"
#include <sstream>
#include <cstdlib>
#include <ctime>

int	main(void)
{
	CentralBureaucracy		cb;
	std::ostringstream		os;
	Bureaucrat				*tagel;

	srand(time(NULL));
	for(int i = 0; i < 20; i++)
	{
		os << i;
		tagel = new Bureaucrat(os.str(), rand() % 150 + 1);
		cb.hire(*tagel);
		delete tagel;
		os << i;
		cb.queueUp(os.str());
	}
	cb.doBureaucracy();
	return (0);
}
