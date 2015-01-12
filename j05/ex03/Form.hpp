/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwoodrow <jwoodrow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 16:03:55 by jwoodrow          #+#    #+#             */
/*   Updated: 2015/01/12 16:07:58 by jwoodrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_H
# define FORM_H

#include "Bureaucrat.hpp"

class Form
{
	private:
		std::string		name;
		bool			signed;
		int				grade;
		Form(void);
		Form(std::string, int);
		Form(Form&);
		~Form(void);
		Form		&operator=(Form&);
		void		beSigned(Bureaucrat&);
}

#endif
