/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 18:59:35 by vkatason          #+#    #+#             */
/*   Updated: 2024/08/19 15:29:16 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("Animal")
{
    std::cout << GREEN<< "Default animal constructor called" << std::endl;
}

Animal::Animal(std::string type) : _type(type)
{
    std::cout << GREEN << "Animal " << type << " constructor called" << RST << std::endl;
}

Animal::Animal(const Animal &copy) : _type(copy._type)
{
    std::cout << GREEN << "Animal copy constructor called for " << copy._type << RST << std::endl;
}

Animal &Animal::operator=(const Animal &rhs)
{
    if (this != &rhs)
    {
        this->_type = rhs._type;
    }
    std::cout << GREEN << "Animal assignment operator called for " << rhs._type << RST << std::endl;
    return (*this);
}

Animal::~Animal()
{
    std::cout << RED << "Animal destructor called for " << this->_type << RST << std::endl;
}

void Animal::makeSound() const
{
    std::cout << BLUE << "Animal sound" << RST << std::endl;
}

std::string Animal::getType() const
{
    return (this->_type);
}