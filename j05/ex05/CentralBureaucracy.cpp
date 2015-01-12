/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CentralBureaucracy.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwoodrow <jwoodrow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 17:31:34 by jwoodrow          #+#    #+#             */
/*   Updated: 2015/01/12 17:31:35 by jwoodrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CentralBureaucracy.hpp"

CentralBureaucracy::CentralBureaucracy(void)
{}

CentralBureaucracy::CentralBureaucracy(CentralBureaucracy const &bureau)
{}

CentralBureaucracy::~CentralBuraucracy(void)
{
    delete [] this->offices;
    this->targets->deleteAll();
}

CentralBureaucracy            &CentralBureaucracy::operator=(CentralBureaucracy const &bureau)
{
    this->offices = bureau.offices;
    this->targets = bureau.targets;
}

CentralBureaucracy::String::String(void){}
CentralBureaucracy::String::String(std::string value) : value(value), next(NULL), last(this){}
CentralBureaucracy::String::String(CentralBureaucracy::String const &string)
{
    *this = string;
}
CentralBureaucracy::String::~String(void){};
CentralBureaucracy::String            &CentralBureaucracy::String::operator=(CentralBureaucracy::String const &string)
{
    this->value.assign(string.value);
    this->next = next;
    this->last = last;
    return (*this);
}
