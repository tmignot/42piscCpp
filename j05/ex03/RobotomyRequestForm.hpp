/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwoodrow <jwoodrow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 17:09:02 by jwoodrow          #+#    #+#             */
/*   Updated: 2015/01/12 17:09:06 by jwoodrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMY_REQUEST_FORM_H
#define ROBOTOMY_REQUEST_FORM_H

#include "Form.hpp"
#include "Bureaucrat.hpp"

class RobotomyRequestForm : public Form {

	private :
		std::string _target;

		RobotomyRequestForm();
		RobotomyRequestForm(RobotomyRequestForm const&);
		RobotomyRequestForm& operator=(RobotomyRequestForm const&);

	public :

		RobotomyRequestForm(std::string const&);
		~RobotomyRequestForm();

		virtual void	execute(Bureaucrat const &);
};

#endif
