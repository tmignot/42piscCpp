#ifndef ROBOTOMY_REQUEST_FORM_HPP
#define ROBOTOMY_REQUEST_FORM_HPP

#include "Form.hpp"
#include "Bureaucrat.hpp"

class RobotomyRequestForm : public Form {

	private :
		std::string _target;

		RobotomyRequestForm();
		RobotomyRequestForm(RobotomyRequestForm const&);
		RobotomyRequestForm& operator=(RobotomyRequestForm const&);

	public :

		RobotomyRequestForm(std::string const&);
		~RobotomyRequestForm();

		virtual void	execute(Bureaucrat const &);
};

#endif
