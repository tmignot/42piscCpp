#ifndef CONVERTER_H
# define CONVERTER_H

#include <string>
#include <stack>
#include <iostream>

class Converter
{
	private:
		std::string			infix;
		std::string			postfix;
		std::stack<char>	stack;
		int					getWeight(char);
		Converter			&operator=(Converter const&);
		Converter(Converter const&);

	public:
		Converter(void);
		~Converter(void);
		void			setExpression(std::string expression);
		std::string		getPostfix(void);
};

#endif
