/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 21:42:42 by vkatason          #+#    #+#             */
/*   Updated: 2024/08/08 00:22:44 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
	: _name("ClapTrap"), _health(10), _energy(10), _damage(0)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
	: _name(name), _health(10), _energy(10), _damage(0)
{
	std::cout << GREEN << "ClapTrap " << name << " constructor called" << RST << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	std::cout << GREEN << "ClapTrap " << copy._name << " copy constructor called" << RST << std::endl;
	*this = copy;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &rhs)
{
	std::cout << GREEN << "ClapTrap " << rhs._name << " assignation operator called" << RST << std::endl;
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_health = rhs._health;
		this->_energy = rhs._energy;
		this->_damage = rhs._damage;
	}
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << RED << "ClapTrap destructor called for " << this->_name << RST << std::endl;
}

std::string ClapTrap::getName() const
{
    return (this->_name);
}

unsigned int ClapTrap::getHealth() const
{
    return (this->_health);
}

unsigned int ClapTrap::getEnergy() const
{
    return (this->_energy);
}

unsigned int ClapTrap::getDamage() const
{
    return (this->_damage);
}

void ClapTrap::attack(std::string const &target)
{
	if(this->_energy > 0)
    {
        this->_energy -= 1;
        std::cout << BLUE << " ⚔️ ClapTrap " << this->_name << " attack " << target << ", causing " << this->_damage << " damage points!" << RST << std::endl;
    }
    else if (this->_health == 0)
    {
        std::cout << BG_BLACK << " 🪦 ClapTrap " << this->_name << " is dead! Let him Rest In Peace! " << RST << std::endl;
    }
    else
    {
        std::cout << RED << " 🪫 ClapTrap " << this->_name << " is out energy to attack!" << RST << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_health == 0)
		std::cout << RED << " ☠️ ClapTrap " << this->_name << " is dead! You can't damage dead body!" << RST << std::endl;
	else if (amount >= this->_health)
	{
		std::cout << RED << " ☠️ ClapTrap " << " takes " << this->_health << " damage points and dies! RIP!" << RST << std::endl;
		this->_health = 0;
        this->_energy = 0;
	}
	else
	{
		this->_health -= amount;
		std::cout << YELLOW << " ☠️ ClapTrap " << this->_name << " takes " << amount << " damage points! Still alive..." << RST << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->_health > 0)
    {
        this->_health += amount;
        this->_energy -= 1;
        std::cout << GREEN << " 💉 ClapTrap " << this->_name << " recieved " << amount << " health points!" << RST << std::endl;
    }
    else
    {
        std::cout << RED << " ☠️ OOOOPS! You can't repaire dead body! ClapTrap " << this->_name << " is already dead!" << RST << std::endl; 
    }
}

    

