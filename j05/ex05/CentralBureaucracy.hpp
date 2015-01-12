/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CentralBureaucracy.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwoodrow <jwoodrow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 17:14:27 by jwoodrow          #+#    #+#             */
/*   Updated: 2015/01/12 19:31:57 by jwoodrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CENTRAL_BUREAUCRACY_H
# define CENTRAL_BUREAUCRACY_H

#include "OfficeBlock.hpp"

class CentralBureaucracy
{
	private:
		class String
		{
			private:
				std::string					value;
			public:
				String						*next;
				String						*last;
				String(void);
				String(std::string);
				String(String const&);
				~String(void);
				String						&operator=(String const&);
				std::string					*pop(void);
				void						add(std::string);
				void						deleteAll(void);
		};
		OfficeBlock							*offices[20];
		CentralBureaucracy::String			*targets;
		Bureaucrat							*waiting;

	public:
		CentralBureaucracy(void);
		CentralBureaucracy(CentralBureaucracy const&);
		~CentralBureaucracy(void);
		CentralBureaucracy					&operator=(CentralBureaucracy const&);
		void								hire(Bureaucrat&);
		void								queueUp(std::string);
		void								doBureaucracy(void);
};

#endif
