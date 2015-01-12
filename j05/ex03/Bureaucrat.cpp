#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(std::string const& name, unsigned int grade)
: _name(name), _grade(grade)
{
	if (_grade < 1)
		throw GradeTooHighException();
	else if (_grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::~Bureaucrat() {}

std::string 		Bureaucrat::getName() const { return _name; }
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

void        Bureaucrat::signForm(Form & form)
{
  try {
    form.beSigned(*this);
    std::cout << "Bureaucrat " << _name << " signs " << form.getName() << std::endl;
  }
  catch (Form::GradeTooLowException e)
  {
    std::cout << "Bureaucrat " << _name << " cannot sign Form " << form.getName() << " because " << e.what() << std::endl;
  }
}

void		Bureaucrat::executeForm(Form & form)
{
	try {
		std::cout << _name << " executes " << form.getName() << std::endl;
		form.execute(*this);
	}
	catch (std::exception& e){
		std::cout << getName() << " could not execute " << form.getName() << " because " << e.what() << std::endl;
	}
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
