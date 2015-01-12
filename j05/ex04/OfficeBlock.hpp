#ifndef OFFICEBLOCK_HPP
#define OFFICEBLOCK_HPP

#include <iostream>
#include <string>

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "Form.hpp"

class OfficeBlock {
  public:
    OfficeBlock();
    OfficeBlock(Intern *, Bureaucrat *, Bureaucrat *);
    ~OfficeBlock();

    void  setIntern(Intern *);
    void  setSigner(Bureaucrat *);
    void  setExecutor(Bureaucrat *);


    void  doBureaucracy(std::string, std::string);

		class NoFormException : public std::exception {

			private :
				NoFormException& operator=(NoFormException const&);

			public :
				NoFormException();
				NoFormException(NoFormException const&);
				~NoFormException() throw();

				virtual const char 	*what() const throw();
		};

		class CantSignException : public std::exception {

			private :
				CantSignException& operator=(CantSignException const&);

			public :
				CantSignException();
				CantSignException(CantSignException const&);
				~CantSignException() throw();

				virtual const char 	*what() const throw();
		};

		class CantExecuteException : public std::exception {

			private :
				CantExecuteException& operator=(CantExecuteException const&);

			public :
				CantExecuteException();
				CantExecuteException(CantExecuteException const&);
				~CantExecuteException() throw();

				virtual const char 	*what() const throw();
		};

  private:
    OfficeBlock(OfficeBlock const &);
    OfficeBlock & operator=(OfficeBlock const &);

    Intern *      _intern;
    Bureaucrat *  _signing;
    Bureaucrat *  _executing;
};

#endif
