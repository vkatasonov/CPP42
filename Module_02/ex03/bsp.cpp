/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 19:30:29 by vkatason          #+#    #+#             */
/*   Updated: 2024/08/07 20:31:33 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/**
 * @brief       Helper function to calculate 
 *              the area of the triangle
 *              formed by the three points
 *              (point, vertex1, vertex2).
 *              The formula used is:
 *              (p(x) - b(x)) * (a(y) - b(y)) 
 *              - (a(x) - b(x)) * (p(y) - b(y))
 *              where a, b, and p are the three
 *              points and x, y are the coordinates.
 */
float	area(Point const point, Point const vertex1, Point const vertex2)
{
	return ((point.getX().toFloat() - vertex2.getX().toFloat())
		* (vertex1.getY().toFloat() - vertex2.getY().toFloat())
		- (vertex1.getX().toFloat() - vertex2.getX().toFloat())
		* (point.getY().toFloat() - vertex2.getY().toFloat()));
}

/**
 * @brief   Function checks if the point is inside the triangle
 *          formed by the three vertices of the triangle
 *          by checking if the sum of the areas of the three 
 *          triangles formed by the point and the
 *          vertices of the triangle is equal to the area
 *          of the triangle. It exvlude cases when the point
 *          is on the edge of the triangle by checking if the
 *          area of internal triangles is greater than 0.
 */
bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	float triangle, area1, area2, area3;
	triangle = area(a, b, c);
	area1 = area(point, a, b);
	area2 = area(point, b, c);
	area3 = area(point, c, a);
    if ((triangle == (area1 + area2 + area3)) && (area1 > 0) && (area2 > 0)
		&& (area3 > 0))
		return (true);
	else
		return (false);
}
