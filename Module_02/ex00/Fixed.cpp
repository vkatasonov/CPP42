/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 18:27:06 by vkatason          #+#    #+#             */
/*   Updated: 2024/08/07 05:15:50 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
	: _raw_bits(0)
{
	std::cout << BG_GREEN << "Default constructor called" << RST << std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << BG_BLUE << "Copy constructor called" << RST << std::endl;
	*this = copy;
}

Fixed &Fixed::operator=(const Fixed &src)
{
	std::cout << BG_ORANGE << "Copy assignment operator called" << RST << std::endl;
	if (this != &src)
		this->_raw_bits = src.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << BG_RED << "Destructor called" << RST << std::endl;
}

int Fixed::getRawBits(void) const
{
	std::cout << BG_YELLOW << "getRawBits member function called" << RST << std::endl;
	return (this->_raw_bits);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << BG_YELLOW << "setRawBits member function called" << RST << std::endl;
	this->_raw_bits = raw;
}
