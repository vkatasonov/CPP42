/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 18:51:48 by vkatason          #+#    #+#             */
/*   Updated: 2024/08/07 20:49:23 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point()
	: _x(0), _y(0)
{
}

Point::Point(const Fixed &x, const Fixed &y)
	: _x(x), _y(y)
{
}

Point::Point(const Point &copy)
	: _x(copy._x), _y(copy._y)
{
}

/**
 * @brief   Overload of the assignation operator '=' for the Point class.
 *          This function will print an error message and return the 
 *          current object as soons as it impossible to assign values to
 *          const variables.
 */
Point &Point::operator=(const Point &src)
{
	(void)src;
	std::cout << RED << "ERROR:" << RST << std::endl;
	std::cout << RED << "Impossible to assign values to const variables." << RST << std::endl;
	std::cout << YELLOW << "Values will remain the same as in the default constructor" << RST << std::endl;
	std::cout << YELLOW << "x: " << _x << std::endl;
	std::cout << YELLOW << "y: " << _y << std::endl;
	return (*this);
}

Point::~Point()
{
}

Fixed const Point::getX() const
{
    return (this->_x);
}

Fixed const Point::getY() const
{
    return (this->_y);
}