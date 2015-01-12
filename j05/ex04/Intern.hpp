/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwoodrow <jwoodrow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 16:03:08 by jwoodrow          #+#    #+#             */
/*   Updated: 2015/01/12 17:30:24 by jwoodrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_H
# define INTERN_H

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardon.hpp"

class Intern
{
	public:
		Intern(void);
		Intern(Intern const&);
		~Intern(void);
		Intern			&Intern::operator=(Intern const&);
		Form			*Intern::MakeForm(std::string, std::string);
};

#endif
