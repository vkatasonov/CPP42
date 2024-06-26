/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:30:23 by vkatason          #+#    #+#             */
/*   Updated: 2024/06/26 16:17:03 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <string>

class PhoneBook
{
private:
	
	static int	_total;
	
	Contact		_contacts[8];
	int			_index;

public:
	
	// Empty constructor
	PhoneBook();

	// Empty destructor
	~PhoneBook();

	// Getters functions
	Contact	getContact(int index) const;	// Get contact by index
	int		getTotalContacts() const;		// Gets number of all contacts

	// Setters functions
	void	setContact(Contact contact);	// Set contact
};

#endif