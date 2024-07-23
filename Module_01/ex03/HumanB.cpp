/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 15:01:58 by vkatason          #+#    #+#             */
/*   Updated: 2024/07/23 17:08:27 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

/**
 * @brief       Parameterized constructor
 *              that initializes the name
 *              of the human and takes a weapon
 *              as a pointer to the weapon
 *              in order to check if the weapon
 *              is set or not 
 */
HumanB::HumanB(std::string name)
	: _name(name), _weapon(nullptr)
{
}
// Destructor
HumanB::~HumanB()
{
}
// Setter function for the weapon
void HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}

/**
 * @brief       Attack function.
 *              Prints the name 
 *              of the human 
 *              and the weapon type
 *              he attacks with in 
 *              case the weapon is set.
 *              If not it prints 
 *              that the human
 *              attacks with nails and teeth
 */
void HumanB::attack() const
{
	if (this->_weapon)
		std::cout << WHITE << BG_RED << std::setw(20) << " " + this->_name
			+ " attacks with " + this->_weapon->getType() + " " + RST << std::endl;
    else 
        std::cout << WHITE << BG_YELLOW << std::setw(20) << " " + this->_name
			+ " attacks with nails and teeth " + RST << std::endl;
}
