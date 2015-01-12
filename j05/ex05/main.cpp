#include "Intern.hpp"

int	main(void)
{
	Intern		intern;
	Form			*shrubbery;
	Form			*robotomy;
	Form			*pardon;

	shrubbery = intern.makeForm("Shrubbery Creation", "King Arthur");
	robotomy = intern.makeForm("Robotomy Request", "Bender");
	pardon = intern.makeForm("Presidential Pardon", "Zaphod Beeblebrox");
	Bureaucrat b("toto", 20);
	b.signForm(*shrubbery);
	b.executeForm(*shrubbery);
	b.signForm(*robotomy);
	b.executeForm(*robotomy);
	b.signForm(*pardon);
	b.executeForm(*pardon);
	intern.makeForm("Exercice Prefilled", "Student");
	return (0);
}
