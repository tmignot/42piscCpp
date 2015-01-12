#include "OfficeBlock.hpp"
//#include "Bureaucrat.hpp"
//#include "Intern.hpp"
//#include "Form.hpp"
//#include "ShrubberyCreationForm.hpp"
//#include "RobotomyRequestForm.hpp"
//#include "PresidentialPardonForm.hpp"

#include <iostream>

int main ()
{
  {
    Intern idiotOne ;
    Bureaucrat hermes( "Hermes Conrad" , 37);
    Bureaucrat bob( "Bobby Bobson" , 123);
    OfficeBlock ob ; ob .  setIntern (&idiotOne); ob .  setSigner (&bob); ob .  setExecutor (&hermes);

    try
    {
      ob .  doBureaucracy ( "Shrubbery Creation" , "Pigley");
    }
    catch (OfficeBlock::NoFormException e)
    {
      std::cout << "NoFormException: " << e.what() << std::endl;
    }
    catch (OfficeBlock::CantSignException e)
    {
      std::cout << "CantSignException: " << e.what() << std::endl;
    }
    catch (OfficeBlock::CantExecuteException e)
    {
      std::cout << "CantExecuteException: " << e.what() << std::endl;
    }
    catch (std :: exception & e)
    {

    }

    try
    {
      ob .  doBureaucracy ( "No request" , "Pigley");
    }
    catch (OfficeBlock::NoFormException e)
    {
      std::cout << "NoFormException: " << e.what() << std::endl;
    }
    catch (OfficeBlock::CantSignException e)
    {
      std::cout << "CantSignException: " << e.what() << std::endl;
    }
    catch (OfficeBlock::CantExecuteException e)
    {
      std::cout << "CantExecuteException: " << e.what() << std::endl;
    }
    catch (std :: exception & e)
    {

    }
  }

  {
    Intern idiotOne ;
    Bureaucrat hermes( "Hermes Conrad" , 37);
    Bureaucrat bob( "Bobby Bobson" , 123);
    OfficeBlock ob ;
    ob .  setIntern (&idiotOne);
    ob .  setSigner (&bob);
    //ob .  setExecutor (&hermes);

    try
    {
      ob .  doBureaucracy ( "Shrubbery Creation" , "Pigley");
    }
    catch (OfficeBlock::NoFormException e)
    {
      std::cout << "NoFormException: " << e.what() << std::endl;
    }
    catch (OfficeBlock::CantSignException e)
    {
      std::cout << "CantSignException: " << e.what() << std::endl;
    }
    catch (OfficeBlock::CantExecuteException e)
    {
      std::cout << "CantExecuteException: " << e.what() << std::endl;
    }
    catch (std :: exception & e)
    {

    }
  }
  {
    Intern idiotOne ;
    Bureaucrat hermes( "Hermes Conrad" , 37);
    Bureaucrat bob( "Bobby Bobson" , 123);
    OfficeBlock ob ;
    ob .  setIntern (&idiotOne);
    // ob .  setSigner (&bob);
    ob .  setExecutor (&hermes);

    try
    {
      ob .  doBureaucracy ( "Shrubbery Creation" , "Pigley");
    }
    catch (OfficeBlock::NoFormException e)
    {
      std::cout << "NoFormException: " << e.what() << std::endl;
    }
    catch (OfficeBlock::CantSignException e)
    {
      std::cout << "CantSignException: " << e.what() << std::endl;
    }
    catch (OfficeBlock::CantExecuteException e)
    {
      std::cout << "CantExecuteException: " << e.what() << std::endl;
    }
    catch (std :: exception & e)
    {

    }
  }
  {
    Intern idiotOne ;
    Bureaucrat hermes( "Hermes Conrad" , 37);
    Bureaucrat bob( "Bobby Bobson" , 123);
    OfficeBlock ob ;
    // ob .  setIntern (&idiotOne);
    ob .  setSigner (&bob);
    ob .  setExecutor (&hermes);

    try
    {
      ob .  doBureaucracy ( "Shrubbery Creation" , "Pigley");
    }
    catch (OfficeBlock::NoFormException e)
    {
      std::cout << "NoFormException: " << e.what() << std::endl;
    }
    catch (OfficeBlock::CantSignException e)
    {
      std::cout << "CantSignException: " << e.what() << std::endl;
    }
    catch (OfficeBlock::CantExecuteException e)
    {
      std::cout << "CantExecuteException: " << e.what() << std::endl;
    }
    catch (std :: exception & e)
    {

    }
  }

  return 0;
}

