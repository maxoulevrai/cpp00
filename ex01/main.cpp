/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 17:11:22 by root              #+#    #+#             */
/*   Updated: 2026/06/05 01:36:56 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cctype>
#include "PhoneBook.hpp"

static void	trim(std::string& str) {
	size_t start = str.find_first_not_of(" \t\n\r");
	if (start == std::string::npos) {
		str.clear();
		return;
	}
	size_t end = str.find_last_not_of(" \t\n\r");
	str = str.substr(start, end - start + 1);
}

static std::string	getLine2(std::string prompt) {
	std::string	tmp;

	while (true) {
		std::cout << prompt;
		if (!std::getline(std::cin, tmp))
			return std::string();
		trim(tmp);
		if (tmp.empty()) {
			std::cout << "Input cannot be empty" << std::endl;
			continue;
		}
		for (size_t i = 0; i < tmp.size(); ++i) {
			if (!std::isalnum(static_cast<unsigned char>(tmp[i]))) {
				std::cout << "Argument must be alphanumerical" << std::endl;
				tmp.clear();
				break;
			}
		}
		if (!tmp.empty())
			return tmp;
	}
}

bool	parseContact(PhoneBook& phone) {
	Contact		newContact;
	std::string tmp;

	tmp = getLine2("First name: ");
	if (tmp.empty())
		return -1;
	newContact.set_first_name(tmp);

	tmp = getLine2("Last name: ");
	if (tmp.empty())
		return -1;
	newContact.set_last_name(tmp);

	tmp = getLine2("Nickname: ");
	if (tmp.empty())
		return -1;
	newContact.set_nickname(tmp);

	tmp = getLine2("Number: ");
	if (tmp.empty())
		return -1;
	newContact.set_number(tmp);

	tmp = getLine2("Secret: ");
	if (tmp.empty())
		return -1;
	newContact.set_secret(tmp);

	phone.add_contact(newContact);
	return 0;
}

int	main()
{
	PhoneBook phone;
	std::string cmd;

	while (true) {
		std::cout << "Enter command (ADD, SEARCH, EXIT): ";
		if (!std::getline(std::cin, cmd))
			return (0);
		trim(cmd);
		if (cmd == "EXIT")
			break;
		else if (cmd == "ADD")
		{
			if (parseContact(phone) == -1)
				continue;
		}
		else if (cmd == "SEARCH")
		{
			if (phone.display_phonebook() == true)
				continue;
			while (true) {
			std::string idxs;
			std::cout << "Enter index to display: ";
			if (!std::getline(std::cin, idxs))
				break;
			trim(idxs);
			if (idxs.empty())
				continue;
			int i = std::atoi(idxs.c_str());
			if (phone.display_contact(i) == true)
				break ;
			}
		}
	}
	return (0);
}



	// try {
	// 	int i = std::stoi(idxs);
	// 	phone.display_contact(i);
	// 	break;
	// } catch (const std::invalid_argument&) {
	// 	std::cout << "Invalid index" << std::endl;
	// } catch (const std::out_of_range&) {
	// 	std::cout << "Invalid index" << std::endl;
	// }