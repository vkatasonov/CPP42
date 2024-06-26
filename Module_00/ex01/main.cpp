/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:38:12 by vkatason          #+#    #+#             */
/*   Updated: 2024/06/26 18:09:29 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

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

int main()
{
    PhoneBook phoneBook;

    std::cout << std::setw(45) << GREEN "┌───────────────────────────────────────────┐" RST << std::endl;
    std::cout << std::setw(45) << (std::string(GREEN) + "|" + RST + BLUE + "          Welcome to the PhoneBook!        " + GREEN + "|" RST) << std::endl;
    std::cout << std::setw(45) << GREEN "├───────────────────────────────────────────┤" RST << std::endl;
    std::cout << std::setw(45) << GREEN "|     Please, type the command to choose:   |" RST << std::endl;
    std::cout << std::setw(45) << GREEN "|                                           |" RST << std::endl;
    std::cout << std::setw(45) << (std::string(GREEN) + "|" + RST + YELLOW + " • ADD\t" + RST + "\tto add the contact" + GREEN + "          |" + RST) << std::endl;
    std::cout << std::setw(45) << (std::string(GREEN) + "|" + RST + YELLOW + " • SEARCH\t" + RST + "to search for a contact" + GREEN + "     |" + RST) << std::endl;
    std::cout << std::setw(45) << (std::string(GREEN) + "|" + RST + RED + " • EXIT\t" + RST + "to exit this app" + GREEN + "            |" + RST) << std::endl;
    std::cout << std::setw(45) << GREEN "└───────────────────────────────────────────┘" RST << std::endl;
}