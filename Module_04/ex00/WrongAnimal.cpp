/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 14:57:11 by vkatason          #+#    #+#             */
/*   Updated: 2024/08/19 15:13:38 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	type = "WrongAnimal";
	std::cout << GREEN << "Default WrongAnimal constructor called" << RST << std::endl;
}

WrongAnimal::WrongAnimal(std::string type)
{
    this->type = type;
    std::cout << GREEN << "WrongAnimal " << type << " constructor called" << RST << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
    this->type = copy.type;
    std::cout << GREEN << "WrongAnimal copy constructor called for " << copy.type << RST << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &wronganimal)
{
    if (this == &wronganimal)
        return (*this);
    this->type = wronganimal.type;
    std::cout << GREEN << "WrongAnimal assignation operator called for " << wronganimal.type << RST << std::endl;
    return (*this);
}

WrongAnimal::~WrongAnimal()
{
    std::cout << RED << "WrongAnimal destructor called" << RST << std::endl;
}

std::string WrongAnimal::getType() const
{
    return (type);
}

void WrongAnimal::makeSound() const
{
    std::cout << RED << "WrongAnimal makes strange sound" << RST << std::endl;
}


