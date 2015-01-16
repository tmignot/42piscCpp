#include "Converter.hpp"

Converter::Converter(void) : infix(""), postfix(""), stack(std::stack<char>())
{}

Converter::~Converter(void)
{}

std::string		Converter::getPostfix(void)
{
	return (this->postfix);
}

int				Converter::getWeight(char ch) {
	switch (ch) {
		case '/':
		case '*': return 2;
		case '+':
		case '-': return 1;
		default : return 0;
	}
}

void			Converter::setExpression(std::string expression)
{
	this->infix.assign(expression);
	int weight;
	int i = 0;
	int k = 0;
	char ch;
	std::cout << "Tokens: ";
	while (i < expression.length()) {
		ch = this->infix[i];
		if (ch == '(') {
			// simply push the opening parenthesis
			std::cout << "ParOpen";
			this->stack.push(ch);
			i++;
			continue;
		}
		if (ch == ')') {
			// if we see a closing parenthesis,
			// pop of all the elements and append it to
			// the postfix expression till we encounter
			// a opening parenthesis
			std::cout << "ParClose";
			while (!this->stack.empty() && this->stack.top() != '(') {
				this->postfix += this->stack.top();
				this->stack.pop();

			}
			// pop off the opening parenthesis also
			if (!this->stack.empty()) {
				this->stack.pop();
			}
			i++;
			continue;
		}
		weight = this->getWeight(ch);
		if (weight == 0) {
			int			n = 0;
			while (isdigit(ch))
			{
				// we saw an operand
				// simply append it to postfix expression
				n *= 10;
				n += ch - '0';
				this->postfix += ch;
				ch = this->infix[++i];
				weight = this->getWeight(ch);
			}
			std::cout << "Num(" << n << ")";
			this->postfix += '.';
			--i;
		}
		else {
			// we saw an operator
			std::cout << "Op(" << ch << ")";
			if (this->stack.empty()) {
				// simply push the operator onto stack if
				// stack is empty
				this->stack.push(ch);
			}
			else {
				// pop of all the operators from the stack and
				// append it to the postfix expression till we
				// see an operator with a lower precedence that
				// the current operator
				while (!this->stack.empty() && this->stack.top() != '(' &&
						weight <= this->getWeight(this->stack.top())) {
					this->postfix += this->stack.top();
					this->stack.pop();

				}
				// push the current operator onto stack
				this->stack.push(ch);
			}
		}
		i++;
		if (i < expression.length())
			std::cout << " ";
	}
	std::cout << std::endl;
	// pop of the remaining operators present in the stack
	// and append it to postfix expression 
	while (!this->stack.empty()) {
		this->postfix += this->stack.top();
		this->stack.pop();
	}
}
