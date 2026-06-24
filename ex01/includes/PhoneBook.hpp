/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maleca <maleca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 16:48:02 by root              #+#    #+#             */
/*   Updated: 2026/06/23 22:05:33 by maleca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>

class PhoneBook {
	private:
		Contact	contacts[8];
		int		idx;
	public:
		PhoneBook();
		void	add_contact(const Contact& new_contact);
		bool	display_contact(int i) const;
		bool	display_phonebook() const;
};

#endif