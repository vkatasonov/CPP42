/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 18:27:06 by vkatason          #+#    #+#             */
/*   Updated: 2024/08/07 19:35:50 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _raw_bits(0)
{
	std::cout << BG_GREEN << "Default constructor called" << RST << std::endl;
}

Fixed::Fixed(int const value)
{
	std::cout << BG_GREEN << "Int constructor called" << RST << std::endl;
	this->_raw_bits = (value << _bits);
}

Fixed::Fixed(float const value)
{
	std::cout << BG_GREEN << "Float constructor called" << RST << std::endl;
	// here foundf function is used to round the float value to the nearest integer 
	this->_raw_bits = roundf(value * (1 << _bits));
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
	return (this->_raw_bits);
}

void Fixed::setRawBits(int const raw)
{
	this->_raw_bits = raw;
}

int Fixed::toInt(void) const
{
	return (this->_raw_bits >> _bits);
}

float Fixed::toFloat(void) const
{
	return ((float)this->_raw_bits / (1 << _bits)); // 1 << _bits is equal to 2^_bits
}

std::ostream &operator<<(std::ostream &o, const Fixed &fixed)
{
	o << fixed.toFloat();
	return (o);
}

