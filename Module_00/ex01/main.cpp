/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:38:12 by vkatason          #+#    #+#             */
/*   Updated: 2024/07/11 18:01:41 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <limits>

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
            phoneBook.addContact();
        }
        else if (command == "SEARCH")
        {
            phoneBook.searchContact();
        }
        else if (command == "EXIT")
        {
            break;
        }
    }
}
