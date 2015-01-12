/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwoodrow <jwoodrow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 17:09:10 by jwoodrow          #+#    #+#             */
/*   Updated: 2015/01/12 17:09:14 by jwoodrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIAL_PARDON_FORM_H
#define PRESIDENTIAL_PARDON_FORM_H

#include "Form.hpp"
#include "Bureaucrat.hpp"

class PresidentialPardonForm : public Form {

	private :
		std::string	_target;

		PresidentialPardonForm();
		PresidentialPardonForm(PresidentialPardonForm const&);
		PresidentialPardonForm& operator=(PresidentialPardonForm const&);

	public :

		PresidentialPardonForm(std::string const&);
		~PresidentialPardonForm();

		virtual void	execute(Bureaucrat const &);
};

#endif
