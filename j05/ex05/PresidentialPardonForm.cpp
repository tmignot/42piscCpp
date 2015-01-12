#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string const& target)
	: Form("Presidential Pardon", 25, 5, false), _target(target)
{}

PresidentialPardonForm::~PresidentialPardonForm() {}

void	PresidentialPardonForm::execute(Bureaucrat const& b) {
	Form::execute(b);
	std::cout << _target << " has been pardoned by Zafod Beeblebrox." << std::endl;
}
