/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 15:01:43 by vkatason          #+#    #+#             */
/*   Updated: 2024/07/24 16:04:05 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

// Parameterized constructor
HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon) {}

// Destructor
HumanA::~HumanA() {}

/**
 * @brief   Attack function
 *          Prints the name 
 *          of the human 
 *          and the weapon type
 *          he attacks with
 */
void HumanA::attack() const
{
    std::cout << WHITE << BG_RED << std::setw(20) << " " + this->_name 
        + " attacks with " + this->_weapon.getType() + " " + RST << std::endl;
}