/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 17:32:03 by vkatason          #+#    #+#             */
/*   Updated: 2024/08/12 17:58:13 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
    : ClapTrap()
{
    std::cout << GREEN << "FragTrap default constructor called" << RST << std::endl;
    this->_health = 100;
    this->_energy = 100;
    this->_damage = 30;
}

FragTrap::FragTrap(std::string name)
    : ClapTrap(name)
{
    std::cout << GREEN << " 👋 FragTrap " << name << " constructor called" << RST << std::endl;
    this->_health = 100;
    this->_energy = 100;
    this->_damage = 30;
}

FragTrap::FragTrap(const FragTrap &copy)
    : ClapTrap(copy)
{
    std::cout << GREEN << "FragTrap " << copy._name << " copy constructor called" << RST << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &rhs)
{
    std::cout << GREEN << "FragTrap " << rhs._name << " assignation operator called" << RST << std::endl;
    if (this != &rhs)
        ClapTrap::operator=(rhs);
    return (*this);
}

FragTrap::~FragTrap()
{
    std::cout << RED << "FragTrap " << this->_name << " dectructor called" << RST << std::endl;
}

void FragTrap::attack(std::string const &target)
{
    if (this->_energy > 0)
    {
        this->_energy -= 1;
        std::cout << BLUE << " 💣 FragTrap " << this->_name << " attack " << target << ", causing " << this->_damage << " damage points!" << RST << std::endl;
    }
    else if (this->_health == 0)
    {
        std::cout << RED << "FragTrap " << this->_name << " is out of energy!" << RST << std::endl;
    }
}

void FragTrap::highFivesGuys(void)
{
    std::cout << GREEN << "FragTrap " << this->_name << " high fives guys!" << RST << std::endl;
}