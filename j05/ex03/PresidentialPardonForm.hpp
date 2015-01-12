/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwoodrow <jwoodrow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 16:03:55 by jwoodrow          #+#    #+#             */
/*   Updated: 2015/01/12 16:13:22 by jwoodrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIAL_PARDON_FORM_H
# define PRESIDENTIAL_PARDON_FORM_H

#include "Form.hpp"

class PresidentialPardonForm : public Form
{
	private:
		std::string				name;
		bool					signed;
		int						grade;
		PresidentialPardonForm(void);
		PresidentialPardonForm(std::string, int);
		PresidentialPardonForm(PresidentialPardonForm&);
		PresidentialPardonForm(void);
		PresidentialPardonForm	&operator=(PresidentialPardonForm&);
		void					beSigned(Bureaucrat&);
}

#endif
