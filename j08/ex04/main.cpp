#include <iostream>
#include <stack>
#include "PostfixEvaluator.hpp"

std::string		removeSpace(std::string str)
{
	std::string		ret("");
	for (int i = 0; i < str.length(); ++i) {
		if (str[i] > ' ')
			ret += str[i];
	}

	return (ret);
}

int				main(int ac, char **av) 
{
	Converter			cv;
	PostfixEvaluator	pfe;

	if (ac == 2)
	{
		std::string			expression(av[1]);
		expression = removeSpace(expression);
		cv.setExpression(expression);
		pfe.setPostfix(cv);
		pfe.evalPostfix();
		std::cout << "result: " << pfe.getResult() << std::endl;
	}
	return (0);
}
