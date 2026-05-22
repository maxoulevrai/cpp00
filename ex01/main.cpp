/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 17:11:22 by root              #+#    #+#             */
/*   Updated: 2026/05/22 11:25:02 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cstdlib>
#include "PhoneBook.hpp"

int	main()
{
	PhoneBook phone;
	std::string cmd;

	while (true) {
		std::cout << "Enter command (ADD, SEARCH, EXIT): ";
		if (!std::getline(std::cin, cmd))
			return (0);
		if (cmd == "EXIT")
			break;
		else if (cmd == "ADD")
		{
			Contact c;
			std::string tmp;
			std::cout << "First name: ";
			if (!std::getline(std::cin, tmp))
				break;
			c.set_first_name(tmp);
			std::cout << "Last name: ";
			if (!std::getline(std::cin, tmp))
				break;
			c.set_last_name(tmp);
			std::cout << "Nickname: ";
			if (!std::getline(std::cin, tmp))
				break;
			c.set_nickname(tmp);
			std::cout << "Number: ";
			if (!std::getline(std::cin, tmp))
				break;
			c.set_number(tmp);
			std::cout << "Secret: ";
			if (!std::getline(std::cin, tmp))
				break;
			c.set_secret(tmp);
			phone.add_contact(c);
		}
		else if (cmd == "SEARCH")
		{
			phone.display_phonebook();
			std::string idxs;
			std::cout << "Enter index to display: ";
			if (!std::getline(std::cin, idxs))
				break;
			if (idxs.empty())
				continue;
			int i = std::atoi(idxs.c_str());
			phone.display_contact(i);
		}
	}
	return (0);
}
