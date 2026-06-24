/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 17:02:53 by root              #+#    #+#             */
/*   Updated: 2026/06/24 21:41:43 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <string>

PhoneBook::PhoneBook() : idx(0) {}

static std::string format_field(const std::string& s) {
	if (s.length() > 10)
		return s.substr(0, 9) + ".";
	std::string out = s;
	if (out.length() < 10)
		out = std::string(10 - out.length(), ' ') + out;
	return out;
}

void PhoneBook::add_contact(const Contact& new_contact) {
	contacts[idx % 8] = new_contact;
	++idx;
}

bool PhoneBook::display_contact(int i) const {
	if (i < 0 || i >= 8 || i > (this->idx -1) % 8) {
		std::cout << "Invalid index" << std::endl;
		std::cin.clear();
		return false;
	}
	const Contact& c = contacts[i];
	std::cout << "First name: " << c.get_first_name() << std::endl;
	std::cout << "Last  name: " << c.get_last_name() << std::endl;
	std::cout << "Nickname   : " << c.get_nickname() << std::endl;
	std::cout << "Number     : " << c.get_number() << std::endl;
	std::cout << "Secret     : " << c.get_secret() << std::endl;
	return true;
}

bool PhoneBook::display_phonebook() const {
	int count = idx < 8 ? idx : 8;
	if (count == 0) {
		std::cerr << "Phonebook is empty." << std::endl;
		return true ;
	}
	std::cout << std::setw(10) << "Index" << "|"
			  << std::setw(10) << "First name" << "|"
			  << std::setw(10) << "Last name" << "|"
			  << std::setw(10) << "Nickname" << std::endl;
	for (int i = 0; i < count; ++i) {
		std::cout << std::setw(10) << i << "|"
				  << format_field(contacts[i].get_first_name()) << "|"
				  << format_field(contacts[i].get_last_name()) << "|"
				  << format_field(contacts[i].get_nickname()) << std::endl;
	}
	return false ;
}