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
    unsigned int  _grade;

  public:
    Form();
    Form(Form const & form);
    Form(std::string const&, unsigned int, bool);
    Form & operator=(Form const & form);
    ~Form();

    unsigned int  getGrade() const;
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
