/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 18:27:41 by vkatason          #+#    #+#             */
/*   Updated: 2024/08/07 20:50:46 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main ()
{
	const Point a(0.f, 0.f);
	const Point b(5.f, 0.f);
	const Point c(2.5f, 5.f);
	const Point point1(2.5f, 2.f);
	const Point point2(6.f, 6.f);

	if (bsp(a, b, c, point1))
		std::cout << BG_GREEN << "Point 1 is inside the triangle" << RST << std::endl;
	else
		std::cout << BG_RED << "Point 1 is outside the triangle" << RST << std::endl;
	
	if (bsp(a, b, c, point2))
		std::cout << BG_GREEN << "Point 2 is inside the triangle" << RST << std::endl;
	else
		std::cout << BG_RED << "Point 2 is outside the triangle" << RST << std::endl;
	
	//Testcase for incorrect usage of the assignation operator
	Point point3;
	Point point4(1.f, 1.f);
	point3 = point4;
	
	return (0);
}