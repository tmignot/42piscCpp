/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwoodrow <jwoodrow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 17:06:10 by jwoodrow          #+#    #+#             */
/*   Updated: 2015/01/12 17:06:14 by jwoodrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_H
#define FORM_H

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat;

class Form {

  private:
    std::string   _name;
    bool          _signed;
    unsigned int  _gradeSign;
	unsigned int  _gradeExec;

  public:
    Form();
    Form(Form const & form);
    Form(std::string const&, unsigned int, unsigned int, bool);
    Form & operator=(Form const & form);
    ~Form();

    unsigned int  getGradeSign() const;
    unsigned int  getGradeEx() const;
    bool          getSigned() const;
    std::string   getName() const;

    void          beSigned(Bureaucrat const & bureaucrat);

		class GradeTooLowException : public std::exception {

			private :
				GradeTooLowException& operator=(GradeTooLowException const&);

			public :
				GradeTooLowException();
				GradeTooLowException(GradeTooLowException const&);
				~GradeTooLowException() throw();

				virtual const char 	*what() const throw();
		};

		class GradeTooHighException : public std::exception {

			private :
				GradeTooHighException& operator=(GradeTooHighException const&);

			public :
				GradeTooHighException();
				GradeTooHighException(GradeTooHighException const&);
				~GradeTooHighException() throw();

				virtual const char 	*what() const throw();
		};
};

std::ostream& operator<<(std::ostream&, Form const&);

#endif
