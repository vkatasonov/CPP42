/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 18:27:41 by vkatason          #+#    #+#             */
/*   Updated: 2024/08/07 20:32:11 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main(void)
{
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));	
	Fixed const c(Fixed(5.05f) + Fixed(2));
	Fixed const d(Fixed(5.05f) - Fixed(2));
	Fixed const e(Fixed(5.05f) / Fixed(2));
	bool f = (Fixed(5.05f) > Fixed(2));
	bool g = (Fixed(5.05f) != Fixed(5.05f));
	
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;		
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;
	
	std::cout << c << std::endl;
	std::cout << d << std::endl;
	std::cout << e << std::endl;
	std::cout << f << std::endl;
	std::cout << g << std::endl;
	return (0);
}
// Expectable output:
// 0
// 0.00390625
// 0.00390625
// 0.00390625
// 0.0078125
// 10.1016
// 10.1016
// 7.05078
// 3.05078
// 2.52344
// 1
// 0	
// $>
//
// Note:
// If you ever do a division by 0, 
// it is acceptable that the program
// crashes
// Note:
// We don't have to output any messages
// in the standard output like 
// "Copy constructor called" or
// "Destructor called" or any other
