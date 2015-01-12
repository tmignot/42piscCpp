#include "OfficeBlock.hpp"

// Not used and private
OfficeBlock(OfficeBlock const &) : _intern(NULL), _signing(NULL), _executing(NULL) {}
OfficeBlock & operator=(OfficeBlock const & ob) {}

// Used
OfficeBlock::OfficeBlock() : _intern(NULL), _signing(NULL), _executing(NULL) {}

OfficeBlock::OfficeBlock(Intern *intern, Bureaucrat *signing, Bureaucrat *executing)
: _intern(intern), _signing(signing), _executing(executing)
{}

OfficeBlock::~OfficeBlock() {}

void OfficeBlock::doBureaucracy(std::string form_name, std::string target)
{
  Form * form = _intern.makeForm(form_name, target);

  if (form == NULL) {
    throw NoFormException();
  }

  try {
    _signing.signForm(form);
  } catch (Exception e) {
    throw CantSignException();
  }

  try {
    _executing.executeForm(form);
  } catch (Exception e) {
    throw CantExecuteException();
  }

  delete form;
}

void  OfficeBlock::setIntern(Intern *intern)
{
  _intern = intern;
}

void  OfficeBlock::setExecutor(Bureaucrat *executor);
{
  _executing = executor;
}

void  OfficeBlock::setSigner(Bureaucrat *signer);
{
  _signing = signer;
}

OfficeBlock::NoFormException::NoFormException() : std::exception() {}
OfficeBlock::NoFormException::~NoFormException() throw() {}
OfficeBlock::NoFormException::NoFormException(OfficeBlock::NoFormException const & e) : std::exception() {}
const char	*OfficeBlock::NoFormException::what() const throw() { return "No form"; }

OfficeBlock::CantSignException::CantSignException() : std::exception() {}
OfficeBlock::CantSignException::~CantSignException() throw() {}
OfficeBlock::CantSignException::CantSignException(OfficeBlock::CantSignException const & e) : std::exception() {}
const char	*OfficeBlock::CantSignException::what() const throw() { return "Can't sign"; }

OfficeBlock::CantExecuteException::CantExecuteException() : std::exception() {}
OfficeBlock::CantExecuteException::~CantExecuteException() throw() {}
OfficeBlock::CantExecuteException::CantExecuteException(OfficeBlock::CantExecuteException const & e) : std::exception() {}
const char	*OfficeBlock::CantExecuteException::what() const throw() { return "Can't execute"; }
