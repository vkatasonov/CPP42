/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 18:58:32 by vkatason          #+#    #+#             */
/*   Updated: 2024/08/19 17:10:36 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog"), _brain(new Brain())
{
    std::cout << GREEN << "Default Dog constructor called" << RST << std::endl;
}

Dog::Dog(std::string type) : Animal(type), _brain(new Brain())
{
    std::cout << GREEN << "Dog constructor called for" << type << RST << std::endl;
}

Dog::Dog(const Dog &copy) : Animal(copy)
{
    this->_type = copy._type;
    this->_brain = new Brain(*copy._brain);
    std::cout << GREEN << "Dog copy constructor called for " << copy.getType() << RST << std::endl;
}

Dog &Dog::operator=(const Dog &rhs)
{
    if (this != &rhs) {
        this->_type = rhs._type;
        this->_brain = new Brain(*rhs._brain);
    }
    return (*this);
}

Brain *Dog::getBrain() const
{
    return (this->_brain);
}

Dog::~Dog()
{
    delete this->_brain;
    std::cout << RED << "Dog destructor called for " << this->_type << RST << std::endl;
}

void Dog::makeSound() const
{
    std::cout << BLUE << "Bark" << RST << std::endl;
}
