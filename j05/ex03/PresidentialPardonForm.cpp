#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string const& target)
	: Form("Presidential Pardon", 25, 5), _target(target)
{}

PresidentialPardonForm::~PresidentialPardonForm() {}

void	execute(Bureaucrat const &) {}

#endif
