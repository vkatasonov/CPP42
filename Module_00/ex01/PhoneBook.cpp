/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:27:09 by vkatason          #+#    #+#             */
/*   Updated: 2024/06/26 16:42:57 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int PhoneBook::_total = 0;

// Constructor that initiates index to 0 using initializer list
PhoneBook::PhoneBook()
{
    _index = 0;
}

// Empty destructor
PhoneBook::~PhoneBook()
{
}

/**
 * @brief           Gets contact by index
 *
 * @param index     Index of the contact
 * @return Contact  Contact object
 */
Contact PhoneBook::getContact(int index) const
{
    return (this->_contacts[index]);
}

/**
 * @brief           Gets number of all contacts
 *
 * @return int      The number of the contacts in total
 */
int PhoneBook::getTotalContacts() const
{
    return (this->_total);
}

/**
 * @brief           Sets contact
 *
 * @param contact   Contact object
 * @return void
 * @var _contacts   Array of contacts
 * @var _index      Index of the contact
 * @var _total      Counter of the contacts
 * @note            If the total number of contacts
 *                  is less than 8, the total number
 *                  of contacts is incremented by 1.
 *                  Otherwise, the total number of contacts
 *                  remains the same.
 * @note            The index of the contact is taken from 0 to 7
 *                  using the modulo operator.
 */
void PhoneBook::setContact(Contact contact)
{
    this->_contacts[this->_index] = contact;
    if (this->_total < 8)
        this->_total++;
    this->_index = (this->_index + 1) % 8; // Takes index from 0 to 7
}