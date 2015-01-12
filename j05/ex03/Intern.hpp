/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwoodrow <jwoodrow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 16:03:08 by jwoodrow          #+#    #+#             */
/*   Updated: 2015/01/12 16:34:16 by jwoodrow         ###   ########.fr       */
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
		Intern(Intern&);
		~Intern(void);
		Intern			&Intern::operator=(Intern&);
		Form			*Intern::MakeForm(std::string, std::string);
}

#endif
