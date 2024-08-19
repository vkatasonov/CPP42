/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 14:55:43 by vkatason          #+#    #+#             */
/*   Updated: 2024/08/19 15:15:31 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    type = "WrongCat";
    std::cout << GREEN << "Default WrongCat constructor called" << RST << std::endl;
}

WrongCat::WrongCat(std::string type)
{
    this->type = type;
    std::cout << GREEN << "WrongCat " << type << " constructor called" << RST << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy)
{
    this->type = copy.type;
    std::cout << GREEN << "WrongCat copy constructor called for " << copy.type << RST << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &wrongcat)
{
    if (this == &wrongcat)
        return (*this);
    this->type = wrongcat.type;
    std::cout << GREEN << "WrongCat assignation operator called for " << wrongcat.type << RST << std::endl;
    return (*this);
}

WrongCat::~WrongCat()
{
    std::cout << RED << "WrongCat destructor called" << RST << std::endl;
}

void WrongCat::makeSound() const
{
    std::cout << RED << "WrongCat makes strange sound" << RST << std::endl;
}