/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:38:12 by vkatason          #+#    #+#             */
/*   Updated: 2024/06/27 18:47:42 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
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
#define RST "\033[0m"        /* Reset to default color */
#define BU "\033[1;4;0m"     /* Bold and underlined text*/
#define B "\033[1m"          /* Bold text default color */
#define U "\033[4m"          /* Underlined text default color */
#define RED "\033[1;31m"     /* Bold Red*/
#define GREEN "\033[1;32m"   /* Bold Green */
#define YELLOW "\033[1;33m"  /* Bold Yellow */
#define BLUE "\033[1;34m"    /* Bold Blue */
#define MAGENTA "\033[1;35m" /* Bold Magenta */
#define CYAN "\033[1;36m"    /* Bold Cyan */
#define WHITE "\033[1;37m"   /* Bold White */

/**
 * @brief               Function to add contact to the phonebook
 * 
 * @param phonebook     Phonebook object
 * @return void
 * @var contact         Contact object
 * @var str             String to store user input
 * @note                This function asks user to input
 *                      the contact information and stores
 *                      it in the phonebook. 
 */
void addContact(PhoneBook *phoneBook)
{
    Contact contact;
    std::string str;

    std::cout << BLUE "First name: " RST;
    std::getline(std::cin, str);
    contact.setFirstName(str);
    std::cout << BLUE "Last name: " RST;
    std::getline(std::cin, str);
    contact.setLastName(str);
    std::cout << BLUE "Nickname: " RST;
    std::getline(std::cin, str);
    contact.setNickName(str);
    std::cout << BLUE "Phone number: " RST;
    std::getline(std::cin, str);
    contact.setPhoneNumber(str);
    std::cout << RED "Darkest secret: " RST;
    std::getline(std::cin, str);
    contact.setDarkestSecret(str);
    phoneBook->setContact(contact);
    std::cout << std::setw(45) << GREEN "┌───────────────────────────────────────────┐" RST << std::endl;
    std::cout << std::setw(45) << GREEN "|          Contact had been added!          |" RST << std::endl;
    std::cout << std::setw(45) << GREEN "└───────────────────────────────────────────┘" RST << std::endl;
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
 * @brief               Function to search the contact
 * 
 * @param phoneBook     PhoneBook object
 * @var index           Index of the contact
 * @var total           Total number of contacts
 * @var i               Counter to iterate through the contacts
 * @var contact         Contact object
 * @var tmp             Temporary contact object
 *                      to store the contact information that
 *                      will be displayed
 */
void searchContact(PhoneBook *phoneBook)
{
	int index;
	int total;
    int i;

	total = phoneBook->getTotalContacts();
	std::cout << GREEN "┌──────────┬──────────┬──────────┬──────────┐" RST << std::endl;
	std::cout << GREEN "|" << std::setw(10) << std::right << "Index";
	std::cout << GREEN "│" << std::setw(10) << std::right << "First name";
	std::cout << GREEN "│" << std::setw(10) << std::right << "Last name";
	std::cout << GREEN "│" << std::setw(10) << std::right << "Nickname" << "│" RST << std::endl;
	std::cout << GREEN "├──────────┼──────────┼──────────┼──────────┤" RST << std::endl;
    i = 0;
    while (i < phoneBook->getTotalContacts())
    {
        Contact contact;
        contact = phoneBook->getContact(i);
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
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << RED "ERROR. ENTER VALID INDEX (1 TO " << total << "): " RST;
		}
		index--;
		Contact tmp;
		tmp = phoneBook->getContact(index);
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
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the input buffer
}

/** 
 * @brief               Function to display the menu
 *                      with the commands to the user 
*/
void displayMenu() {
    std::cout << std::setw(45) << GREEN "┌───────────────────────────────────────────┐" RST << std::endl;
    std::cout << std::setw(45) << GREEN "|        Please, choose the command         |" RST << std::endl;
    std::cout << std::setw(45) << GREEN "|             and type it below:            |" RST << std::endl;
    std::cout << std::setw(45) << GREEN "|                                           |" RST << std::endl;
    std::cout << std::setw(45) << (std::string(GREEN) + "|" + RST + " • " + YELLOW + "ADD\t" + RST + "\tto add the contact" + GREEN + "          |" + RST) << std::endl;
    std::cout << std::setw(45) << (std::string(GREEN) + "|" + RST + " • " + YELLOW + "SEARCH\t" + RST + "to search for a contact" + GREEN + "     |" + RST) << std::endl;
    std::cout << std::setw(45) << (std::string(GREEN) + "|" + RST + " • " + RED + "EXIT\t" + RST + "to exit this app" + GREEN + "            |" + RST) << std::endl;
    std::cout << std::setw(45) << GREEN "└───────────────────────────────────────────┘" RST << std::endl;
}

int main()
{
    PhoneBook phoneBook;
    std::string command;

    std::cout << std::setw(45) << BLUE "          Welcome to the PhoneBook!          " RST << std::endl;
    while (1)
    {
        std::string command;
        displayMenu();
        std::cout << GREEN "Enter command: " RST;
        std::getline(std::cin, command);
        if (command == "ADD")
        {
            addContact(&phoneBook);
        }
        else if (command == "SEARCH")
        {
            searchContact(&phoneBook);
        }
        else if (command == "EXIT" || command == "")
        {
            break;
        }
    }
}