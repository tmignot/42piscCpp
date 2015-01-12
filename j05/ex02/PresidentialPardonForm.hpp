#ifndef PRESIDENTIAL_PARDON_FORM_HPP
#define PRESIDENTIAL_PARDON_FORM_HPP

#include "Form.hpp"
#include "Bureaucrat.hpp"

class PresidentialPardonForm : public Form {

	private :
		std::string	_target;

		PresidentialPardonForm();
		PresidentialPardonForm(PresidentialPardonForm const&);
		PresidentialPardonForm& operator=(PresidentialPardonForm const&);

	public :

		PresidentialPardonForm(std::string const&);
		~PresidentialPardonForm();

		virtual void	execute(ureaucrat const &);
};

#endif
