/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:27:09 by vkatason          #+#    #+#             */
/*   Updated: 2024/07/14 18:47:27 by vkatason         ###   ########.fr       */
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

/**
 * @brief               Function to add the contact
 * @var contact         Contact object
 * @var inputPrompt     Array of input prompts
 * @var inputError      Array of input errors
 * @var inputValues     Array of input values
 * @var inputValid      Boolean variable to check 
 *                      if the input is valid when 
 *                      entering the phone number
 * @var i               Counter to iterate through 
 *                      the input prompts
 * 
 * @return true         If the contact is successfully added
 * @return false        If the user terminates the program
 *                      by pressing the Ctrl+D key combination
 *                      (checking EOF character)
 */
bool PhoneBook::addContact()
{
    Contact contact;
    std::string inputPrompt[] = {"First name: ", "Last name: ", "Nickname: ", "Phone number: ", "Darkest secret: "};
    std::string inputError[] = {"", "", "", "ERROR. PHONE NUMBER MUST CONTAIN ONLY DIGITS!", ""};
    std::string inputValues[5]; // Array to store input values
    bool inputValid = true;

    for (int i = 0; i < 5; ++i) 
    {
        while (true) 
        {
            std::cout << BLUE << inputPrompt[i] << RST;
            std::getline(std::cin, inputValues[i]);
            if (std::cin.eof()) 
            {
                std::cout << RED "\nERROR: Terminated by user:" << std::endl;
                std::cout << YELLOW "EOF reached or CTRL+D pressed" RST << std::endl;
                return false;
            }
            if (inputValues[i] != "") 
            {
                if (i == 3) 
                {                                               // Special validation for phone number
                    inputValid = true;
                    for (size_t j = 0; j < inputValues[i].length(); ++j) {
                        char c = inputValues[i][j];
                        if (!std::isdigit(c)) {
                            std::cout << RED << inputError[i] << RST << std::endl;
                            inputValid = false;
                            break;                              // Exit the loop if a non-digit character is found
                        }
                    }
                    if (!inputValid) continue;                  // If invalid, restart the loop for phone number
                }
                break;                                          // Break the loop if input is valid
            }
        }
    }
    // Setting the contact details after validation
    contact.setFirstName(inputValues[0]);
    contact.setLastName(inputValues[1]);
    contact.setNickName(inputValues[2]);
    contact.setPhoneNumber(inputValues[3]);
    contact.setDarkestSecret(inputValues[4]);
    this->setContact(contact);
    std::cout << std::setw(45) << GREEN "┌───────────────────────────────────────────┐" RST << std::endl;
    std::cout << std::setw(45) << GREEN "|          Contact had been added!          |" RST << std::endl;
    std::cout << std::setw(45) << GREEN "└───────────────────────────────────────────┘" RST << std::endl;
    return true;
}

/**
 * @brief               Function to cut the string
 *                      to make it no longer than 10 
 *                      characters long
 * 
 * @param str           String to cut
 * @return std::string  Truncated string
 */
std::string cutString(std::string str) {
    return str.size() >= 10 ? str.substr(0, 9) + "." : str;
}

/**
 * @brief            Function to search for the contact
 * @var index        Index of the contact
 * @var total        Total number of contacts
 * @var i            Counter to iterate through the contacts
 * @var contact      Contact object
 * 
 * @return true      If the search is successful and if 
 *                   during the search the user does not
 *                   terminate the program by pressing
 *                   the Ctrl+D key combination 
 *                   (checking EOF character)
 */
bool PhoneBook::searchContact() 
{
    int index;
    int total;
    int i;
    
    total = this->getTotalContacts();
    std::cout << GREEN "┌──────────┬──────────┬──────────┬──────────┐" RST << std::endl;
    std::cout << GREEN "|" << std::setw(10) << std::right << "Index";
    std::cout << GREEN "│" << std::setw(10) << std::right << "First name";
    std::cout << GREEN "│" << std::setw(10) << std::right << "Last name";
    std::cout << GREEN "│" << std::setw(10) << std::right << "Nickname" << "│" RST << std::endl;
    std::cout << GREEN "├──────────┼──────────┼──────────┼──────────┤" RST << std::endl;
    i = 0;
    while (i < this->getTotalContacts())
    {
        Contact contact;
        contact = this->getContact(i);
        std::cout << GREEN "|" RST << std::setw(10) << i + 1;
        std::cout << GREEN "|" RST << std::setw(10) << cutString(contact.getFirstName());
        std::cout << GREEN "|" RST << std::setw(10) << cutString(contact.getLastName());
        std::cout << GREEN "|" RST << std::setw(10) << cutString(contact.getNickName()) << GREEN "|" RST << std::endl;
        i++;
    }
    std::cout << GREEN "└──────────┴──────────┴──────────┴──────────┘" RST << std::endl;
    if (total > 0) 
    {
        std::cout << GREEN "Please, enter the index of the contact:" RST;
        while (!(std::cin >> index) || index > total || index < 1) 
        {
            if (std::cin.eof()) 
            {
                std::cout << RED "\nERROR: Terminated by user:" << std::endl;
                std::cout << YELLOW "EOF reached or CTRL+D pressed" RST << std::endl;
                return false;
            }
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << RED "ERROR. ENTER VALID INDEX (1 TO " << total << "): " RST;
        }
        index--;
        Contact tmp;
        tmp = this->getContact(index);
        std::cout << std::endl << BLUE "Contact information:" RST << std::endl;
        std::cout << YELLOW "First name: \t\t" RST << tmp.getFirstName() << std::endl;
		std::cout << YELLOW "Last name: \t\t" RST << tmp.getLastName() << std::endl;
		std::cout << YELLOW "Nickname: \t\t" RST << tmp.getNickName() << std::endl;
		std::cout << YELLOW "Phone number: \t\t" RST << tmp.getPhoneNumber() << std::endl;
		std::cout << RED "Darkest secret\t\t" RST << tmp.getDarkestSecret() << std::endl;
        std::cout << std::endl;
    } 
    else 
    {
        std::cout << RED "Phone Book is empty!" << std::endl;
        return true;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the input buffer
    return true;
}