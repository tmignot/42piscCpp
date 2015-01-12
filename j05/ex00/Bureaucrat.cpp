#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string const& name, unsigned int grade)
: _name(name), _grade(grade)
{
	if (_grade < 1)
		throw GradeTooHighException();
	else if (_grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::~Bureaucrat() {}

std::string			Bureaucrat::getName() const { return _name; }
unsigned int		Bureaucrat::getGrade() const { return _grade; }

void				Bureaucrat::incGrade()
{
	if (_grade == 1)
		throw GradeTooHighException();
	else
		_grade--;
}

void				Bureaucrat::decGrade()
{
	if (_grade == 150)
		throw GradeTooLowException();
	else
		_grade++;
}


Bureaucrat::GradeTooHighException::GradeTooHighException() : std::exception() {}
Bureaucrat::GradeTooHighException::~GradeTooHighException() throw() {}
const char	*Bureaucrat::GradeTooHighException::what() const throw() { return "Grade too high"; }

Bureaucrat::GradeTooLowException::GradeTooLowException() : std::exception() {}
Bureaucrat::GradeTooLowException::~GradeTooLowException() throw() {}
const char	*Bureaucrat::GradeTooLowException::what() const throw() { return "Grade too low"; }

std::ostream& operator<<(std::ostream& o, Bureaucrat const& b) {
	o << b.getName() << ", bureaucrat lvl " << b.getGrade() << std::endl;
	return o;
}
