/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 18:59:09 by vkatason          #+#    #+#             */
/*   Updated: 2024/09/19 14:03:06 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat"), _brain(new Brain())
{
    std::cout << GREEN << "Default Cat constructor called" << RST << std::endl;
}

Cat::Cat (std::string type) : Animal(type), _brain(new Brain())
{
    std::cout << GREEN << "Cat " << type << " constructor called for " << type << RST << std::endl;
}

Cat::Cat(const Cat &copy) : Animal(copy)
{
    this->_type = copy._type;
    this->_brain = new Brain(*copy._brain);
    std::cout << GREEN << "Cat copy constructor called for " << this->_type << RST << std::endl;
}

Cat &Cat::operator=(const Cat &rhs)
{
    if (this != &rhs) {
        delete rhs._brain;
        this->_type = rhs._type;
        this->_brain = new Brain(*rhs._brain);\
    }
    return (*this);
}

Brain *Cat::getBrain() const
{
    return (this->_brain);
}

Cat::~Cat()
{
    delete this->_brain;
    std::cout << RED << "Cat destructor called for " << this->_type << RST << std::endl;
}

void Cat::makeSound() const
{
    std::cout << BLUE << "Meow" << RST << std::endl;
}