/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwoodrow <jwoodrow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 17:08:54 by jwoodrow          #+#    #+#             */
/*   Updated: 2015/01/12 17:08:55 by jwoodrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string const& target)
	: Form("Robotomy Request", 72, 45), _target(target)
{}

RobotomyRequestForm::~RobotomyRequestForm() {}

void	execute(Bureaucrat const &) {}

#endif
