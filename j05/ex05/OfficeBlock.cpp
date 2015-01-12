#include "OfficeBlock.hpp"

// Not used and private
OfficeBlock::OfficeBlock(OfficeBlock const&) : _intern(NULL), _signing(NULL), _executing(NULL) {}
OfficeBlock & OfficeBlock::operator=(OfficeBlock const&) { return *this; }

// Used
OfficeBlock::OfficeBlock() : _intern(NULL), _signing(NULL), _executing(NULL) {}

OfficeBlock::OfficeBlock(Intern *intern, Bureaucrat *signing, Bureaucrat *executing)
: _intern(intern), _signing(signing), _executing(executing)
{}

OfficeBlock::~OfficeBlock() {}

void OfficeBlock::doBureaucracy(std::string form_name, std::string target)
{
  if (_intern == NULL)
    throw NoFormException();

  Form * form = _intern->makeForm(form_name, target);
  if (form == NULL) {
    throw NoFormException();
  }

  if (_signing == NULL)
    throw CantSignException();

  try {
    _signing->signForm(*form);
  } catch (std::exception e) {
    throw CantSignException();
  }

  if (_executing == NULL)
    throw CantExecuteException();

  try {
    _executing->executeForm(*form);
  } catch (std::exception e) {
    throw CantExecuteException();
  }
}

void  OfficeBlock::setIntern(Intern *intern)
{
  _intern = intern;
}

void  OfficeBlock::setExecutor(Bureaucrat *executor)
{
  _executing = executor;
}

void  OfficeBlock::setSigner(Bureaucrat *signer)
{
  _signing = signer;
}

OfficeBlock::NoFormException::NoFormException() : std::exception() {}
OfficeBlock::NoFormException::~NoFormException() throw() {}
OfficeBlock::NoFormException::NoFormException(OfficeBlock::NoFormException const&) : std::exception() {}
const char	*OfficeBlock::NoFormException::what() const throw() { return "No form"; }

OfficeBlock::CantSignException::CantSignException() : std::exception() {}
OfficeBlock::CantSignException::~CantSignException() throw() {}
OfficeBlock::CantSignException::CantSignException(OfficeBlock::CantSignException const&) : std::exception() {}
const char	*OfficeBlock::CantSignException::what() const throw() { return "Can't sign"; }

OfficeBlock::CantExecuteException::CantExecuteException() : std::exception() {}
OfficeBlock::CantExecuteException::~CantExecuteException() throw() {}
OfficeBlock::CantExecuteException::CantExecuteException(OfficeBlock::CantExecuteException const&) : std::exception() {}
const char	*OfficeBlock::CantExecuteException::what() const throw() { return "Can't execute"; }
