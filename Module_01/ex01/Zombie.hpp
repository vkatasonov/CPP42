/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 12:47:41 by vkatason          #+#    #+#             */
/*   Updated: 2024/07/19 12:33:59 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
#include <iostream>
#include <iomanip>
#include <string>

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

class Zombie
{
private:
    std::string _name;

public:
    // Default constructor
    Zombie();
    // Parameterized constructor with name
    explicit Zombie(std::string name);
    // Destructor
    ~Zombie();

    //setter and getter methods
    void setName(std::string name);
    std::string getName(void) const;

    // Announce method
    void announce(void) const;
};

Zombie* zombieHorde( int N, std::string name );

#endif