/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maleca <maleca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 17:11:22 by root              #+#    #+#             */
/*   Updated: 2026/06/24 00:17:21 by maleca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/PhoneBook.hpp"
#include <cctype>

static void	trim(std::string& str) {
	size_t start = str.find_first_not_of(" \t\n\r");
	if (start == std::string::npos) {
		str.clear();
		return;
	}
	size_t end = str.find_last_not_of(" \t\n\r");
	str = str.substr(start, end - start + 1);
}

static std::string	getLine2(std::string prompt, int (*f)( int), std::string err_msg) {
	std::string	tmp;

	while (true) {
		std::cout << prompt;
		if (!std::getline(std::cin, tmp))
			return std::string();
		else if (std::cin.eof()) {
			std::cout << "eof: exiting program.";
			exit (0);
		}
		trim(tmp);
		if (tmp.empty()) {
			std::cerr << "Error: Input cannot be empty" << std::endl;
			continue;
		}
		for (size_t i = 0; i < tmp.size(); ++i) {
			if (!f(static_cast<unsigned char>(tmp[i]))) {
				std::cerr << "Error: " << err_msg << std::endl;
				tmp.clear();
				break;
			}
		}
		if (!tmp.empty())
			return tmp;
	}
}

static bool	parseContact(PhoneBook& phone) {
	Contact		newContact;
	std::string tmp;

	tmp = getLine2("First name: ", std::isalpha, 
			"argument may only contain letters.");
	if (tmp.empty())
		return true;
	newContact.set_first_name(tmp);

	tmp = getLine2("Last name: ", std::isalpha,
			"argument may only contain letters.");
	if (tmp.empty())
		return true;
	newContact.set_last_name(tmp);

	tmp = getLine2("Nickname: ", std::isalnum, 
			"argument may only contain letters and numbers.");
	if (tmp.empty())
		return true;
	newContact.set_nickname(tmp);

	tmp = getLine2("Number: ", std::isdigit, 
			"argument may only contain numbers.");
	if (tmp.empty())
		return true;
	newContact.set_number(tmp);

	tmp = getLine2("Secret: ", std::isalnum, 
			"argument may only contain letters and numbers.");
	if (tmp.empty())
		return true;
	newContact.set_secret(tmp);

	phone.add_contact(newContact);
	return false;
}

static int	parseIdx(void) {
	while (true) {
		std::string idxs = getLine2("Enter index to display: ", std::isdigit,  
				"index may only take numbers as argument");
		if (idxs.empty()) 
			return (-1);
		trim(idxs);
		int i = atoi(idxs.c_str());
		return (i);
	}
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
		else if (cmd == "ADD") {
			if (!parseContact(phone))
				continue;
		}
		else if (cmd == "SEARCH") {
			if (phone.display_phonebook() == true)
				continue;
			while (true) {
			int i = parseIdx();
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