#ifndef INTERN_H
# define INTERN_H

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	private:
		Intern			&operator=(Intern const&);

	public:
		Intern(void);
		~Intern(void);
		Intern(Intern const&);
		Form			*makeForm(std::string, std::string);
};

#endif
