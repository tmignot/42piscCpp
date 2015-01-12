#ifndef INTERN_H
# define INTERN_H

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	private:
		Intern(Intern const&);
		Intern			&operator=(Intern const&);

	public:
		Intern(void);
		~Intern(void);
		Form			*makeForm(std::string, std::string);
};

#endif
