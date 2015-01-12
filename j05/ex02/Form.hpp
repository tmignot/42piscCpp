#ifndef FORM_HPP
#define FORM_HPP

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

  public :
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
	void		  execute(Bureaucrat const & bureaucrat);

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

		class RequireHigherGradeException : public std::exception {

			private :
				RequireHigherGradeException& operator=(RequireHigherGradeException const&);

			public :
				RequireHigherGradeException();
				RequireHigherGradeException(RequireHigherGradeException const&);
				~RequireHigherGradeException() throw();

				virtual const char 	*what() const throw();
		};

		class FormNotSignedException : public std::exception {

			private :
				FormNotSignedException& operator=(FormNotSignedException const&);

			public :
				FormNotSignedException();
				FormNotSignedException(FormNotSignedException const&);
				~FormNotSignedException() throw();

				virtual const char 	*what() const throw();
		};
};

std::ostream& operator<<(std::ostream&, Form const&);

#endif
