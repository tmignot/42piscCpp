#ifndef POSTFIX_EVALUATOR_H
# define POSTFIX_EVALUATOR_H

# include "Converter.hpp"
# include <sstream>

class PostfixEvaluator
{
	private:
		std::string			postfix;
		int					result;
		std::stack<int>		stack;
		PostfixEvaluator(PostfixEvaluator const&);
		PostfixEvaluator	&operator=(PostfixEvaluator const&);
		int					eval(int op1, int op2, char operate);
		bool				isOperator(char ch);
		void				printStack(void);
		void				printNum(int n, bool push);
		void				printOp(char ch, bool push);
		std::string			opToStr(char op);

	public:
		PostfixEvaluator(void);
		~PostfixEvaluator(void);
		void				evalPostfix(void);
		int					getResult(void);
		void				setPostfix(Converter &cv);
};

#endif
