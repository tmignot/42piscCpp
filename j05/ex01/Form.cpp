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

Form::Form() : _name("Untitled"), _signed(false), _gradeSign(150), _gradeExec(150)
{}

Form::Form(Form const & form) : _name(form.getName()), _signed(form.getSigned()), 
	_gradeSign(form.getGradeSign()), _gradeExec(form.getGradeEx())
{}

Form & Form::operator=(Form const & form)
{
  _name = form.getName();
  _signed = form.getSigned();
  _gradeSign = form.getGradeSign();
  _gradeExec = form.getGradeEx();

  return (*this);
}

Form::Form(std::string const & name, unsigned int gradeSign, unsigned int gradeExec, bool is_signed) : _name(name), _gradeSign(gradeSign), _gradeExec(gradeExec), _signed(is_signed)
{
	if (_gradeSign < 1 || _gradeExec < 1)
		throw GradeTooHighException();
	else if (_gradeSign > 150 || _gradeExec > 150)
		throw GradeTooLowException();
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

unsigned int  Form::getGradeSign() const
{
  return (_gradeSign);
}

unsigned int  Form::getGradeEx() const
{
	return (_gradeExec);
}

void          Form::beSigned(Bureaucrat const & bureaucrat)
{
  if (bureaucrat.getGrade() <= _gradeSign)
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
  os << "Form '" << form.getName() << "' sign grade " << form.getGradeSign() << " exec grade " << form.getGradeEx();
  if (form.getSigned())
    os << " signed";
  else
    os << " not signed";

  return (os);
}
