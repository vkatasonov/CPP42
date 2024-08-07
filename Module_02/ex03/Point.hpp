/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 18:52:22 by vkatason          #+#    #+#             */
/*   Updated: 2024/08/07 19:29:48 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP
# include "Fixed.hpp"

class Point
{
    private:
        Fixed const _x;
        Fixed const _y;
    
    public:
        Point();                                // default constructor
        Point(const Fixed &x, const Fixed &y);  // parameterized constructor
        Point(const Point &copy);               // copy constructor
        Point &operator=(const Point &src);     // assignation operator overload
        ~Point();                               // destructor
        
        /*Getters for point coordinates*/
        
        Fixed const getX() const;
        Fixed const getY() const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif