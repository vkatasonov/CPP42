/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 10:28:03 by vkatason          #+#    #+#             */
/*   Updated: 2024/09/20 14:57:56 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>
#include <deque>
#include <iostream>

/*
** ASCII colors escape sequences for printing
*/
#define RST "\033[0m"					            /* Reset to default color */
#define BU "\033[1;4;0m"				            /* Bold and underlined text*/
#define BOLD "\033[1m"						        /* Bold text default color */
#define UNDER "\033[4m"								/* Underlined text default color */
#define RED "\033[1;31m"				            /* Bold Red*/
#define GREEN "\033[1;32m"				            /* Bold Green */
#define YELLOW "\033[1;33m"				            /* Bold Yellow */
#define BLUE "\033[1;34m"				            /* Bold Blue */
#define MAGENTA "\033[1;35m"			            /* Bold Magenta */
#define CYAN "\033[1;36m"				            /* Bold Cyan */
#define WHITE "\033[1;37m"				            /* Bold White */
#define ORANGE "\033[1m\033[38;2;255;165;0m"	    /* Orange */
#define VIOLET "\033[1m\033[38;2;238;130;238m"	    /* Violet */
#define BG_BLACK "\033[40m"				            /* Background Black */
#define BG_GREEN "\033[42m"				            /* Background Green */
#define BG_YELLOW "\033[43m"			            /* Background Yellow */
#define BG_RED "\033[41m"				            /* Background Red */
#define BG_BLUE "\033[44m"				            /* Background Blue */
#define BG_MAGENTA "\033[45m"			            /* Background Magenta */
#define BG_CYAN "\033[46m"				            /* Background Cyan */
#define BG_WHITE "\033[47m"				            /* Background White */
#define BG_ORANGE "\033[48;2;255;165;0m"            /* Background Orange */
#define BG_VIOLET "\033[48;2;238;130;238m"          /* Background Violet */
#define BG_RESET "\033[49m"				            /* Background Reset */

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
public:
    // Default constructor
    MutantStack();

    // Copy constructor
    MutantStack(const MutantStack<T, Container> &other);

    // Assignment operator overload
    MutantStack<T, Container> &operator=(const MutantStack<T, Container> &rhs);

    // Destructor
    virtual ~MutantStack();

	// Print the stack
	void printMutantStack() const;
	
	// Iterators
    typedef typename Container::iterator iterator;
    typedef typename Container::reverse_iterator reverse_iterator;
	
    iterator begin();
    iterator end();
    reverse_iterator rbegin();
    reverse_iterator rend();
};

#include "MutantStack.tpp"