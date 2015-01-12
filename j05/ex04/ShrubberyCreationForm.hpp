#ifndef SHRUBERRY_CREATION_FORM_HPP
#define SHRUBERRY_CREATION_FORM_HPP

#include "Form.hpp"
#include "Bureaucrat.hpp"

class ShrubberyCreationForm : public Form {

	private :

		std::string	_target;

		ShrubberyCreationForm();
		ShrubberyCreationForm(ShrubberyCreationForm const&);
		ShrubberyCreationForm& operator=(ShrubberyCreationForm const&);

	public :

		ShrubberyCreationForm(std::string const&);
		~ShrubberyCreationForm();

		virtual void	execute(Bureaucrat const &);
};

#endif
