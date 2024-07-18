/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 12:47:41 by vkatason          #+#    #+#             */
/*   Updated: 2024/07/18 16:54:00 by vkatason         ###   ########.fr       */
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

class Zombie
{

public:
    Zombie( std::string zombieName );
    ~Zombie();
    
    void announce( void ) const;

private:
    std::string _name;
};

Zombie* newZombie( std::string Name );
void randomChump( std::string name );

#endif