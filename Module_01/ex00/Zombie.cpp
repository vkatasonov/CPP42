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
    std::cout << BLUE << std::setw(20) << this->_name + ":" << RED "is destroyed" RST<< std::endl;
}

void Zombie::announce( void ) const
{
    std::cout << BLUE << std::setw(20) << std::left << this->_name + ":" << YELLOW "BraiiiiiiinnnzzzZ..." RST << std::endl;
}