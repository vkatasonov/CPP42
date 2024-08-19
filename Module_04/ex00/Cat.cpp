/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 18:59:09 by vkatason          #+#    #+#             */
/*   Updated: 2024/08/19 13:42:03 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
    std::cout << GREEN << "Default Cat constructor called" << RST << std::endl;
}

Cat::Cat(std::string type) : Animal(type)
{
    std::cout << GREEN << "Cat " << type << " constructor called" << RST << std::endl;
}

Cat::Cat(const Cat &copy) : Animal(copy)
{
    std::cout << GREEN << "Cat copy constructor called for " << copy.getType() << RST << std::endl;
}

Cat &Cat::operator=(const Cat &rhs)
{
    if (this != &rhs) {
        Animal::operator=(rhs);                         // Call base class assignment operator
        this->_type = rhs._type;
    }
    return (*this);
}

Cat::~Cat()
{
    std::cout << RED << "Cat destructor called for " << this->_type << RST << std::endl;
}

void Cat::makeSound() const
{
    std::cout << BLUE << "Meow" << RST << std::endl;
}