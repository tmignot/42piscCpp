/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwoodrow <jwoodrow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 17:06:20 by jwoodrow          #+#    #+#             */
/*   Updated: 2015/01/12 17:06:22 by jwoodrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Form::Form() : _name("Untitled"), _signed(false), _grade(150)
{}

Form::Form(Form const & form) : _name(form.getName()), _signed(form.getSigned()), _grade(form.getGrade())
{}

Form & Form::operator=(Form const & form)
{
  _name = form.getName();
  _signed = form.getSigned();
  _grade = form.getGrade();

  return (*this);
}

Form::Form(std::string const & name, unsigned int grade, bool is_signed) : _name(name), _grade(grade), _signed(is_signed)
{
	if (_grade < 1)
  {
		throw GradeTooHighException();
    _grade = 1;
  }
	else if (_grade > 150)
  {
    _grade = 150;
		throw GradeTooLowException();
  }
}

Form::~Form()
{}

std::string   Form::getName() const
{
  return (_name);
}

bool          Form::getSigned() const
{
  return (_signed);
}

unsigned int  Form::getGrade() const
{
  return (_grade);
}

void          Form::beSigned(Bureaucrat const & bureaucrat)
{
  if (bureaucrat.getGrade() <= _grade)
    _signed = true;
  else
    throw GradeTooLowException();
}

Form::GradeTooHighException::GradeTooHighException() : std::exception() {}
Form::GradeTooHighException::GradeTooHighException(Form::GradeTooHighException const & e) : std::exception() {}
Form::GradeTooHighException::~GradeTooHighException() throw() {}
const char	*Form::GradeTooHighException::what() const throw() { return "Grade too high"; }

Form::GradeTooLowException::GradeTooLowException() : std::exception() {}
Form::GradeTooLowException::GradeTooLowException(Form::GradeTooLowException const & e) : std::exception() {}
Form::GradeTooLowException::~GradeTooLowException() throw() {}
const char	*Form::GradeTooLowException::what() const throw() { return "Grade too low"; }

std::ostream& operator<<(std::ostream & os, Form const & form)
{
  os << "Form '" << form.getName() << "' grade " << form.getGrade();
  if (form.getSigned())
    os << " signed";
  else
    os << " not signed";

  return (os);
}
