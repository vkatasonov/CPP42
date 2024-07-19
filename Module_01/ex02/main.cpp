/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 13:43:27 by vkatason          #+#    #+#             */
/*   Updated: 2024/07/19 14:26:30 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <iomanip>

/*
** ASCII colors escape sequences for printf
** Usage:
**      ft_printf(RED "Red bold text" RST);
**		ft_printf(B "Bold text goes here" RST);
*/
#define RST "\033[0m"         /* Reset to default color */
#define BU "\033[1;4;0m"      /* Bold and underlined text*/
#define B "\033[1m"           /* Bold text default color */
#define U "\033[4m"           /* Underlined text default color */
#define RED "\033[1;31m"      /* Bold Red*/
#define GREEN "\033[1;32m"    /* Bold Green */
#define YELLOW "\033[1;33m"   /* Bold Yellow */
#define BLUE "\033[1;34m"     /* Bold Blue */
#define MAGENTA "\033[1;35m"  /* Bold Magenta */
#define CYAN "\033[1;36m"     /* Bold Cyan */
#define WHITE "\033[1;37m"    /* Bold White */
#define BG_BLACK "\033[40m"   /* Background Black */
#define BG_GREEN "\033[42m"   /* Background Green */
#define BG_YELLOW "\033[43m"  /* Background Yellow */
#define BG_RED "\033[41m"     /* Background Red */
#define BG_BLUE "\033[44m"    /* Background Blue */
#define BG_MAGENTA "\033[45m" /* Background Magenta */
#define BG_CYAN "\033[46m"    /* Background Cyan */
#define BG_WHITE "\033[47m"   /* Background White */

int main()
{
	// Initialize a string variable
	std::string str = "HI THIS IS BRAIN";
	// Pointer to the string
	std::string* stringPTR = &str;
	// Reference to the string
	std::string& stringREF = str;

	// Print the memory address of the string variable
	std::cout << WHITE << BG_BLUE << std::setw(32) << std::left << " Address of the string variable: " << BG_YELLOW << " " << &str << " " RST << std::endl;
	// Print the memory address held by stringPTR
	std::cout << WHITE << BG_BLUE << std::setw(32) << std::left << " Address held by stringPTR: " << BG_YELLOW << " " << stringPTR << " " RST << std::endl;
	// Print the memory address held by stringREF
	std::cout << WHITE << BG_BLUE << std::setw(32) << std::left << " Address held by stringREF: " << BG_YELLOW << " " << &stringREF << " " RST << std::endl;

	// Print the value of the string variable
	std::cout << WHITE << BG_YELLOW << std::setw(32) << std::left << " Value of the string variable: " << BG_BLUE << " " << str << " " RST << std::endl;
	// Print the value pointed to by stringPTR
	std::cout << WHITE << BG_YELLOW << std::setw(32) << std::left << " Value pointed to by stringPTR: " << BG_BLUE << " " << *stringPTR << " " RST << std::endl;
	// Print the value pointed to by stringREF
	std::cout << WHITE << BG_YELLOW << std::setw(32) << std::left << " Value pointed to by stringREF: " << BG_BLUE << " " << stringREF << " " RST << std::endl;

	return 0;
}
