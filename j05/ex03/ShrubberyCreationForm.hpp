/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwoodrow <jwoodrow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 16:03:55 by jwoodrow          #+#    #+#             */
/*   Updated: 2015/01/12 16:13:22 by jwoodrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERY_CREATION_FORM_H
# define SHRUBBERY_CREATION_FORM_H

#include "Form.hpp"

class ShrubberyCreationForm : public Form
{
	private:
		std::string				name;
		bool					signed;
		int						grade;
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(std::string, int);
		ShrubberyCreationForm(ShrubberyCreationForm&);
		ShrubberyCreationForm(void);
		ShrubberyCreationForm	&operator=(ShrubberyCreationForm&);
		void					beSigned(Bureaucrat&);
}

#endif
