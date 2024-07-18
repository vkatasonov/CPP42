#include "Zombie.hpp"
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 12:47:12 by vkatason          #+#    #+#             */
/*   Updated: 2024/07/17 12:47:19 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie( std::string name ) : _name(name)
{
}
Zombie::~Zombie()
{
    std::cout << WHITE << BG_RED << std::setw(25) << " " + this->_name + ":" << "is destroyed " RST<< std::endl;
}

void Zombie::announce( void ) const
{
    std::cout << WHITE << BG_GREEN << std::setw(25) << std::left << " " + this->_name + ":" << "BraiiiiiiinnnzzzZ... " RST << std::endl;
}