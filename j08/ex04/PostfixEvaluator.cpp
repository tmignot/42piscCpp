#include "PostfixEvaluator.hpp"

PostfixEvaluator::PostfixEvaluator(void) : postfix(""), stack(std::stack<int>()), result(0)
{}

PostfixEvaluator::~PostfixEvaluator(void)
{}

int				PostfixEvaluator::getResult(void)
{
	return (this->result);
}

void			PostfixEvaluator::setPostfix(Converter &cv)
{
	this->postfix.assign(cv.getPostfix());
	int i = 0;
	char ch;
	std::cout << "Postfix: ";
	while (i < this->postfix.length()) {
		ch = this->postfix[i];
		if (isdigit(ch)) {
			int		n = 0;
			while (isdigit(ch))
			{
				n *= 10;
				n += ch - '0';
				ch = this->postfix[++i];
			}
			// we saw an operand
			// push the digit onto stack
			std::cout << "Num(" << n << ")";
			this->stack.push(n);
		}
		else if (this->isOperator(ch))
		{
			// we saw an operator
			// pop off the top two operands from the
			// stack and evalute them using the current
			// operator
			std::cout << "Op(" << ch << ")";
			int op1 = this->stack.top();
			this->stack.pop();
			int op2 = this->stack.top();
			this->stack.pop();
			this->result = this->eval(op1, op2, ch);
			// push the value obtained after evaluating
			// onto the stack
			this->stack.push(this->result);
		}
		i++;
		if (i < this->postfix.length())
			std::cout << " ";
	}
	while (!this->stack.empty())
		this->stack.pop();
	std::cout << std::endl;
}

int				PostfixEvaluator::eval(int op1, int op2, char operate) {
	switch (operate)
	{
		case '*':
			return (op2 * op1);
		case '/':
			return (op2 / op1);
		case '+':
			return (op2 + op1);
		case '-':
			return (op2 - op1);
		default :
			return (0);
	}
}

bool			PostfixEvaluator::isOperator(char ch)
{
	return (ch == '+' || ch == '-' || ch == '/' || ch == '*');
}


void			PostfixEvaluator::printStack(void)
{
	std::stack<int> tmp(this->stack);

	std::cout << "ST ";
	while (!tmp.empty())
	{
		std::cout << tmp.top();
		tmp.pop();
		if (!tmp.empty())
			std::cout << " ";
	}
	std::cout << "]" << std::endl;
}

void			PostfixEvaluator::printNum(int n, bool push)
{
	std::stringstream		ss;
	ss << n;
	if (push)
	{
		std::cout << "[ ";
		std::cout.width(20);
		std::string		tmp = "Num(";
		tmp += ss.str();
		tmp += ")";
		std::cout << std::left << tmp;
		std::cout << "| ";
		std::cout.width(20);
		std::string		push("NUM PUSH");
		std::cout << std::left << push;
		std::cout << "| ";
	}
	else
	{
		std::cout << "[ ";
		std::cout.width(20);
		std::string		tmp = "Num(";
		tmp += ss.str();
		tmp += ")";
		std::cout << std::left << tmp;
		std::cout << "| ";
		std::cout.width(20);
		std::string		push("NUM POP");
		std::cout << std::left << push;
		std::cout << "| ";
	}
	this->printStack();
}

std::string		PostfixEvaluator::opToStr(char op)
{
	switch(op)
	{
		case '+':
			return ("Add");
		case '-':
			return ("Substract");
		case '*':
			return ("Multiply");
		case '/':
			return ("Divide");
	}
}

void			PostfixEvaluator::printOp(char ch, bool push)
{
	std::cout << "[ ";
	std::cout.width(20);
	std::string		tmp = "OP(";
	tmp += ch;
	tmp += ")";
	std::cout << std::left << tmp;
	std::cout << "| ";
	std::cout.width(20);
	std::string		pushs("OP " + this->opToStr(ch));
	std::cout << std::left << pushs;
	std::cout << "| ";
	this->printStack();
}

// evaluates the postfix operation
// this module neither supports multiple digit integers
// nor looks for valid expression
// However it can be easily modified and some additional
// code can be added to overcome the above mentioned limitations
// it's a simple function which implements the basic logic to
// evaluate postfix operations using stack
void			PostfixEvaluator::evalPostfix(void) {
	int i = 0;
	char ch;
	while (i < this->postfix.length()) {
		ch = this->postfix[i];
		if (isdigit(ch)) {
			int		n = 0;
			while (isdigit(ch))
			{
				n *= 10;
				n += ch - '0';
				ch = this->postfix[++i];
			}
			// we saw an operand
			// push the digit onto stack
			this->stack.push(n);
			this->printNum(n, true);
		}
		else if (this->isOperator(ch))
		{
			// we saw an operator
			// pop off the top two operands from the
			// stack and evalute them using the current
			// operator
			int op1 = this->stack.top();
			this->stack.pop();
			int op2 = this->stack.top();
			this->stack.pop();
			this->result = this->eval(op1, op2, ch);
			// push the value obtained after evaluating
			// onto the stack
			this->stack.push(this->result);
			this->printOp(ch, true);
		}
		i++;
	}
	while (!this->stack.empty())
		this->stack.pop();
}
