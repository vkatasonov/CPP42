/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 15:01:43 by vkatason          #+#    #+#             */
/*   Updated: 2024/07/23 17:15:22 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
//#include "HumanB.hpp"

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

/**
 * @brief       Main function
 *              to check the functionality
 *              of the correct implementation
 *              of both classes 
 */
// int main()
// {
//     {
//         Weapon club = Weapon("crude spiked club");
//         HumanA bob("Bob", club);
//         bob.attack();
//         club.setType("some other type of club");
//         bob.attack();
//     }
//     {
//         Weapon club = Weapon("crude spiked club");
//         HumanB jim("Jim");
//         //jim.setWeapon(club);
//         jim.attack();
//         club.setType("some other type of club");
//         jim.attack();
//     }
//     return 0;
// }