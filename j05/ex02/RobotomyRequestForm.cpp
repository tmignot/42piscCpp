#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string const& target)
	: Form("Robotomy Request", 72, 45), _target(target)
{}

RobotomyRequestForm::~RobotomyRequestForm() {}

void	execute(Bureaucrat const &) {}

#endif
