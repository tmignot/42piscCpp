/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwoodrow <jwoodrow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 16:03:36 by jwoodrow          #+#    #+#             */
/*   Updated: 2015/01/12 17:10:04 by jwoodrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

int	main(void)
{
	Intern		intern;
	Form			*shrubbery;
	Form			*robotomy;
	Form			*pardon;

	shrubbery = intern.makeForm("Shrubbery Creation", "King Arthur");
	robotomy = intern.makeForm("Robotomy Request", "Bender");
	pardon = intern.makeForm("Presidential Pardon", "Zaphod Beeblebrox")
	intern.makeForm("Exercice Prefilled", "Student");
	return (0);
}
