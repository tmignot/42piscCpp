#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string const& target)
	: Form("Shrubbery Creation", 145, 137, false), _target(target)
{}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void	ShrubberyCreationForm::execute(Bureaucrat const & b) {
	Form::execute(b);
	std::ofstream f((_target + std::string("_shrubbery")).c_str());
	f << "ASCII trees" << std::endl;
	f.close();
}
