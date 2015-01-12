/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwoodrow <jwoodrow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 16:03:08 by jwoodrow          #+#    #+#             */
/*   Updated: 2015/01/12 18:47:45 by mlalisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_H
# define INTERN_H

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	public:
		Intern(void);
		Intern(Intern const&);
		~Intern(void);
		Intern		&operator=(Intern const&);
    Form			*MakeForm(std::string, std::string);
};

#endif
