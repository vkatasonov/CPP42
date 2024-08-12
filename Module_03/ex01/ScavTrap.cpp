/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 14:10:29 by vkatason          #+#    #+#             */
/*   Updated: 2024/08/12 16:29:41 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
    : ClapTrap()
{
    std::cout << GREEN<< "ScavTrap default constructor called" << RST << std::endl;
    this->_health = 100;
    this->_energy = 50;
    this->_damage = 20;
}

ScavTrap::ScavTrap(std::string name)
    : ClapTrap(name)
{
    std::cout << GREEN << "ScavTrap " << name << " constructor called" << RST << std::endl;
    this->_health = 100;
    this->_energy = 50;
    this->_damage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &copy)
    : ClapTrap(copy)
{
	std::cout << GREEN << "ScavTrap " << copy._name << " copy constructor called" << RST << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &rhs)
{
	std::cout << GREEN << "ScavTrap " << rhs._name << " assignation operator called" << RST << std::endl;
	if (this != &rhs)
		ClapTrap::operator=(rhs);
	return (*this);
}

ScavTrap::~ScavTrap()
{
    std::cout << RED << "ScavTrap " << this->_name << " dectructor called" << RST<< std::endl; 
}

void ScavTrap::attack(std::string const &target)
{
	if(this->_energy > 0)
    {
        this->_energy -= 1;
        std::cout << BLUE << " 🔨 ScavTrap " << this->_name << " attack " << target << ", causing " << this->_damage << " damage points!" << RST << std::endl;
    }
    else if (this->_health == 0)
    {
        std::cout << BG_BLACK << " 🪦 ScavTrap " << this->_name << " is dead and can't attack! Let him Rest In Peace! " << RST << std::endl;
    }
    else
    {
        std::cout << RED << " 🪫 ScavTrap " << this->_name << " is out energy to attack!" << RST << std::endl;
    }
}

void ScavTrap::guardGate()
{
    std::cout << ORANGE << "🛡️ ScavTrap " << getName() << " have enterred in Gate keeper mode" << RST << std::endl;
}
