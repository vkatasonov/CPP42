/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 18:58:32 by vkatason          #+#    #+#             */
/*   Updated: 2024/08/19 13:41:38 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
    std::cout << GREEN << "Default Dog constructor called" << RST << std::endl;
}

Dog::Dog(std::string type) : Animal(type)
{
    std::cout << GREEN << "Dog " << type << " constructor called" << RST << std::endl;
}

Dog::Dog(const Dog &copy) : Animal(copy)
{
    std::cout << GREEN << "Dog copy constructor called for " << copy.getType() << RST << std::endl;
}

Dog &Dog::operator=(const Dog &rhs)
{
    if (this != &rhs) {
        Animal::operator=(rhs);             // Call base class assignment operator
        this->_type = rhs._type;
    }
    return (*this);
}

Dog::~Dog()
{
    std::cout << RED << "Dog destructor called for " << this->_type << RST << std::endl;
}

void Dog::makeSound() const
{
    std::cout << BLUE << "Bark" << RST << std::endl;
}