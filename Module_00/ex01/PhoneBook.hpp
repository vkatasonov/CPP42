/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:30:23 by vkatason          #+#    #+#             */
/*   Updated: 2024/07/11 18:43:46 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <limits>

/*
** ASCII colors escape sequences for printf
** Usage:
**      ft_printf(RED "Red bold text" RST);
**		ft_printf(B "Bold text goes here" RST);
*/
#define RST "\033[0m"		 /* Reset to default color */
#define BU "\033[1;4;0m"	 /* Bold and underlined text*/
#define B "\033[1m"			 /* Bold text default color */
#define U "\033[4m"			 /* Underlined text default color */
#define RED "\033[1;31m"	 /* Bold Red*/
#define GREEN "\033[1;32m"	 /* Bold Green */
#define YELLOW "\033[1;33m"	 /* Bold Yellow */
#define BLUE "\033[1;34m"	 /* Bold Blue */
#define MAGENTA "\033[1;35m" /* Bold Magenta */
#define CYAN "\033[1;36m"	 /* Bold Cyan */
#define WHITE "\033[1;37m"	 /* Bold White */

class PhoneBook
{
private:
	static int _total;

	Contact _contacts[8];
	int _index;

	// Setter function
	void setContact(Contact contact);		// Set contact
	
	// Getters functions
	Contact getContact(int index) const;	// Get contact by index
	int getTotalContacts() const;			// Gets number of all contacts

public:
	// Empty constructor
	PhoneBook();

	// Empty destructor
	~PhoneBook();

	void addContact();						// Add contact
	void searchContact();					// Search contact
};

#endif