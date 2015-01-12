#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(std::string const& target)
	: Form("Robotomy Request", 72, 45, false), _target(target)
{}

RobotomyRequestForm::~RobotomyRequestForm() {}

void	RobotomyRequestForm::execute(Bureaucrat const &b) {
	Form::execute(b);
	std::cout << "BRLLBRLMBRLMBRLM" << std::endl;
	srand(time(0));
	if (rand() %2)
		std::cout << _target << " has been robotomized" << std::endl;
	else 
		std::cout << "Failure" << std::endl;
}
