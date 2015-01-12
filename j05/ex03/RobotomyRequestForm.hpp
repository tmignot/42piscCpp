/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwoodrow <jwoodrow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 16:03:55 by jwoodrow          #+#    #+#             */
/*   Updated: 2015/01/12 16:13:22 by jwoodrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMY_REQUEST_FORM_H
# define ROBOTOMY_REQUEST_FORM_H

#include "Form.hpp"

class RobotomyRequestForm : public Form
{
	private:
		std::string				name;
		bool					signed;
		int						grade;
		RobotomyRequestForm(void);
		RobotomyRequestForm(std::string, int);
		RobotomyRequestForm(RobotomyRequestForm&);
		RobotomyRequestForm(void);
		RobotomyRequestForm	&operator=(RobotomyRequestForm&);
		void					beSigned(Bureaucrat&);
}

#endif
