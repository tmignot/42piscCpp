/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwoodrow <jwoodrow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 17:08:46 by jwoodrow          #+#    #+#             */
/*   Updated: 2015/01/12 17:08:49 by jwoodrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBERRY_CREATION_FORM_H
#define SHRUBERRY_CREATION_FORM_H

#include "Form.hpp"
#include "Bureaucrat.hpp"

class ShrubberyCreationForm : public Form {

	private :

		std::string	_target;

		ShrubberyCreationForm();
		ShrubberyCreationForm(ShrubberyCreationForm const&);
		ShrubberyCreationForm& operator=(ShruberryCreationForm const&);

	public :

		ShrubberyCreationForm(std::string const&);
		~ShrubberyCreationForm();

		virtual void	execute(Bureaucrat const &);
};

#endif
