/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwoodrow <jwoodrow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 17:06:53 by jwoodrow          #+#    #+#             */
/*   Updated: 2015/01/12 17:07:40 by jwoodrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main() {

	try {
		Bureaucrat toto(std::string("Toto"), 2);
		std::cout << toto << std::endl;
		toto.incGrade(); 
		std::cout << toto << std::endl;
		toto.incGrade();
	}
	catch (std::exception& e) {
		std::cout << "Fatal: " << e.what() << std::endl;
	}


	try {
		Bureaucrat tata(std::string("Tata"), 149);
		std::cout << tata << std::endl;
		tata.decGrade();
		std::cout << tata << std::endl;
		tata.decGrade();

	} catch (std::exception& e) {
		std::cout << "Fatal: " << e.what() << std::endl;
	}

	try {
		Bureaucrat titi(std::string("Titi"), 0);
		std::cout << titi << std::endl;
	} catch (std::exception& e) {
		std::cout << "Fatal: " << e.what() << std::endl;
	}

	return 0;
}
