/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 16:26:11 by root              #+#    #+#             */
/*   Updated: 2026/05/17 16:47:49 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void		Contact::set_first_name(std::string first_name)
{
	this->first_name = first_name;
}

void		Contact::set_last_name(std::string last_name)
{
	this->last_name = last_name;
}

void		Contact::set_nickname(std::string nickname)
{
	this->nickname = nickname;
}

void		Contact::set_number(std::string number)
{
	this->number = number;
}

void		Contact::set_secret(std::string secret)
{
	this->secret = secret;
}

std::string	Contact::get_first_name(void) const
{
	return (this->first_name);
}

std::string	Contact::get_last_name(void) const
{
	return (this->last_name);
}

std::string	Contact::get_nickname(void) const
{
	return (this->nickname);
}

std::string	Contact::get_number(void) const
{
	return (this->number);
}

std::string	Contact::get_secret(void) const
{
	return (this->secret);
}
