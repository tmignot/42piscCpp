/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwoodrow <jwoodrow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 17:09:19 by jwoodrow          #+#    #+#             */
/*   Updated: 2015/01/12 17:09:20 by jwoodrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string const& target)
	: Form("Presidential Pardon", 25, 5), _target(target)
{}

PresidentialPardonForm::~PresidentialPardonForm() {}

void	execute(Bureaucrat const &) {}

#endif
