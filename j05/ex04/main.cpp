#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#include <iostream>

int	main() {

	try {
		Bureaucrat toto(std::string("Toto"), 2);
		std::cout << toto << std::endl;
		toto.incGrade(); 
		std::cout << toto << std::endl;
		toto.incGrade();
	}
	catch (std::exception& e) {
		std::cout << "Fatal: " << e.what() << std::endl;
	}


	try {
		Bureaucrat tata(std::string("Tata"), 149);
		std::cout << tata << std::endl;
		tata.decGrade();
		std::cout << tata << std::endl;
		tata.decGrade();

	} catch (std::exception& e) {
		std::cout << "Fatal: " << e.what() << std::endl;
	}

	try {
		Bureaucrat titi(std::string("Titi"), 0);
		std::cout << titi << std::endl;
	} catch (std::exception& e) {
		std::cout << "Fatal: " << e.what() << std::endl;
	}


  try {
    Form form("Authorisation prealable aux authorisations temporaires", 50, 50, false);
		Bureaucrat titi(std::string("Titi"), 1);
    titi.signForm(form);
	} catch (std::exception& e) {
		std::cout << "Fatal: " << e.what() << std::endl;
	}

  try {
    Form form("Authorisation prealable aux authorisations temporaires", 50, 50, false);
		Bureaucrat titi(std::string("Titi"), 80);
    titi.signForm(form);
	} catch (std::exception& e) {
		std::cout << "Fatal: " << e.what() << std::endl;
	}

  try {
    Form form("Authorisation prealable aux authorisations temporaires", 0, 0, true);
	}
  catch (std::exception& e) {
		std::cout << "Fatal: " << e.what() << std::endl;
	}

  try {
	  ShrubberyCreationForm s("log");
	  Bureaucrat titi(std::string("Titi"), 80);
	  s.execute(titi);
  }
  catch (std::exception& e) {
	 std::cout << "Fatal: " << e.what() << std::endl;
  }

  try {
	  ShrubberyCreationForm s("log");
	  Bureaucrat titi(std::string("Titi"), 80);
	  s.beSigned(titi);
	  s.execute(titi);
  }
  catch (std::exception& e) {
	 std::cout << "Fatal: " << e.what() << std::endl;
  }

 try {
	  RobotomyRequestForm s("robot");
	  Bureaucrat titi(std::string("Titi"), 40);
	  s.beSigned(titi);
	  s.execute(titi);
  }
  catch (std::exception& e) {
	 std::cout << "Fatal: " << e.what() << std::endl;
  }

  try {
	  PresidentialPardonForm s("presidPard");
	  Bureaucrat titi(std::string("Titi"), 4);
	  s.beSigned(titi);
	  s.execute(titi);
  }
  catch (std::exception& e) {
	 std::cout << "Fatal: " << e.what() << std::endl;
  }

  PresidentialPardonForm s("presidPard");
  RobotomyRequestForm t("robot");
  Bureaucrat titi(std::string("Titi"), 40);
  titi.signForm(t);
  titi.executeForm(t); 
  titi.signForm(s);
  titi.executeForm(s); 
  return 0;
}
