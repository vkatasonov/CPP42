/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 15:01:18 by vkatason          #+#    #+#             */
/*   Updated: 2024/07/23 17:03:21 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

// Parameterized constructor
Weapon::Weapon(std::string type) : _type(type) {};
// Destructor
Weapon::~Weapon() {};

/**
 * @brief   Getter function
 *          to get the type 
 *          of weapon
 * 
 */
const std::string& Weapon::getType()
{
    return this->_type;
}

/**
 * @brief   Setter function
 *          to set the type
 *          of weapon       
 */
void Weapon::setType(const std::string& type)
{
    this->_type = type;
}