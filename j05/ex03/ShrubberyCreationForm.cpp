/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwoodrow <jwoodrow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 17:08:42 by jwoodrow          #+#    #+#             */
/*   Updated: 2015/01/12 17:08:43 by jwoodrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string const& target)
	: Form("Shrubbery Creation", 145, 137), _target(target)
{}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void	execute(Bureaucrat const &) {}
