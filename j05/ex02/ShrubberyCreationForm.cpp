#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string const& target)
	: Form("Shrubbery Creation", 145, 137), _target(target)
{}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void	execute(Bureaucrat const &) {}

#endif
