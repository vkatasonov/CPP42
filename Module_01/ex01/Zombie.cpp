/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 11:34:37 by vkatason          #+#    #+#             */
/*   Updated: 2024/07/19 12:48:13 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// Default constructor
Zombie::Zombie()
{
}
// Parameterized constructor with name
Zombie::Zombie(std::string name) : _name(name)
{
}
// Destructor (with debug message)
Zombie::~Zombie()
{
    std::cout << WHITE << BG_RED << std::setw(20) << " " + this->_name + ":" << "is destroyed " RST<< std::endl;
}
//setter name method
void Zombie::setName(std::string name)
{
    this->_name = name;
}
//getter name method
std::string Zombie::getName(void) const
{
    return this->_name;
}
// Announce method
void Zombie::announce( void ) const
{
    std::cout << WHITE << BG_BLUE << std::setw(20) << std::left << " " + this->_name + ":" << "BraiiiiiiinnnzzzZ... " RST << std::endl;
}
