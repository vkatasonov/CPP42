/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 18:27:06 by vkatason          #+#    #+#             */
/*   Updated: 2024/08/07 17:40:55 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* Default and parameterized constructors and destructor */

Fixed::Fixed()
	: _raw_bits(0)
{
}

Fixed::Fixed(int const value)
{
	this->_raw_bits = (value << _bits);
}

Fixed::Fixed(float const value)
{
	// here foundf function is used
	// to round the float value to the nearest integer
	this->_raw_bits = roundf(value * (1 << _bits));
}

Fixed::Fixed(const Fixed &copy)
{
	*this = copy;
}

Fixed::~Fixed()
{
}

/* Operator overloads */

Fixed &Fixed::operator=(const Fixed &src)
{
	if (this != &src)
		this->_raw_bits = src.getRawBits();
	return (*this);
}

Fixed Fixed::operator+(const Fixed &src)
{
	Fixed	result;

	result.setRawBits(this->_raw_bits + src.getRawBits());
	return (result);
}

Fixed Fixed::operator-(const Fixed &src)
{
	Fixed	result;

	result.setRawBits(this->_raw_bits - src.getRawBits());
	return (result);
}

Fixed Fixed::operator*(const Fixed &src)
{
	Fixed	result;

	result.setRawBits((this->_raw_bits * src.getRawBits()) >> _bits);
	return (result);
}

Fixed Fixed::operator/(const Fixed &src)
{
	Fixed	result;

	result.setRawBits((this->_raw_bits << _bits) / src.getRawBits());
	return (result);
}

/* Comparison operators */

bool Fixed::operator>(const Fixed &src)
{
	return (this->getRawBits() > src.getRawBits());
}

bool Fixed::operator<(const Fixed &src)
{
	return (this->getRawBits() < src.getRawBits());
}

bool Fixed::operator>=(const Fixed &src)
{
	return (this->getRawBits() >= src.getRawBits());
}

bool Fixed::operator<=(const Fixed &src)
{
	return (this->getRawBits() <= src.getRawBits());
}

bool Fixed::operator==(const Fixed &src)
{
	return (this->getRawBits() == src.getRawBits());
}

bool Fixed::operator!=(const Fixed &src)
{
	return (this->getRawBits() != src.getRawBits());
}

/* Increment and decrement operators */

Fixed &Fixed::operator++()
{
	this->_raw_bits++;
	return (*this);
}

Fixed &Fixed::operator--()
{
	this->_raw_bits--;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	operator++();
	return (tmp);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	operator--();
	return (tmp);
}

/* Comparison functions with 
 * two parameters passed as 
 * references to constant 
 * fixed-point numbers */

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return (a);
	return (b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return (a);
	return (b);
}

/* Comparison functions with 
 * two parameters passed as 
 * references to fixed-point numbers */

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

/* Getter and setter functions */

int Fixed::getRawBits(void) const
{
	return (this->_raw_bits);
}

void Fixed::setRawBits(int const raw)
{
	this->_raw_bits = raw;
}

/* Conversion functions */

int Fixed::toInt(void) const
{
	return (this->_raw_bits >> _bits);
}

float Fixed::toFloat(void) const
{
	return ((float)this->_raw_bits / (1 << _bits));
}

/* Insertion operator overload */

std::ostream &operator<<(std::ostream &o, const Fixed &fixed)
{
	o << fixed.toFloat();
	return (o);
}
