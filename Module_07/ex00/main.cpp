/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 10:02:23 by vkatason          #+#    #+#             */
/*   Updated: 2024/09/16 15:10:59 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int	main(void)
{
	int	a = 2;
	int	b = 3;
	std::string c = "chaine1";
	std::string d = "chaine2";
	float e = 42.42f;
	float f = 13.37f;
	double g = 3.14;
	double h = 2.718;
	
	std::cout << YELLOW << "************ Initial values ***********" << RST << std::endl;
	std::cout << BLUE << "a = " << RST << a << std::endl;
	std::cout << BLUE << "b = " << RST << b << std::endl;
	std::cout << BLUE << "c = " << RST << c << std::endl;
	std::cout << BLUE << "d = " << RST << d << std::endl;
	std::cout << BLUE << "e = " << RST << e << std::endl;
	std::cout << BLUE << "f = " << RST << f << std::endl;
	std::cout << BLUE << "g = " << RST << g << std::endl;
	std::cout << BLUE << "h = " << RST << h << std::endl;
	
	std::cout << YELLOW << "************ Test with int ************" << RST << std::endl;
	::swap(a, b);
	std::cout << BLUE << "Swap a and b" << RST << std::endl;
	std::cout << BLUE << "a = " << RST << a << BLUE << "\nb = " << RST << b << std::endl;
	std::cout << BLUE << "min( a, b ) = " << RST << ::min(a, b) << std::endl;
	std::cout << BLUE << "max( a, b ) = " << RST << ::max(a, b) << std::endl;
	
	std::cout << YELLOW << "*********** Test with string **********" << RST << std::endl;
	::swap(c, d);
	std::cout << BLUE << "Swap c and d" << RST << std::endl;
	std::cout << BLUE << "c = " << RST << c << BLUE << "\nd = " << RST << d << std::endl;
	std::cout << BLUE "min( c, d ) = " << RST << ::min(c, d) << std::endl;
	std::cout << BLUE "max( c, d ) = " << RST << ::max(c, d) << std::endl;

	std::cout << YELLOW << "*********** Test with float ***********" << RST << std::endl;
	::swap(e, f);
	std::cout << BLUE << "Swap e and f" << RST << std::endl;
	std::cout << BLUE << "e = " << RST << e << BLUE << "\nf = " << RST << f << std::endl;
	std::cout << BLUE << "min( e, f ) = " << RST << ::min(e, f) << std::endl;
	std::cout << BLUE << "max( e, f ) = " << RST << ::max(e, f) << std::endl;
	
	std::cout << YELLOW << "********** Test with double ***********" << RST << std::endl;
	::swap(g, h);
	std::cout << BLUE << "Swap g and h" << RST << std::endl;
	std::cout << BLUE << "g = " << RST << g << BLUE << "\nh = " << RST << h << std::endl;
	std::cout << BLUE << "min( g, h ) = " << RST << ::min(g, h) << std::endl;
	std::cout << BLUE << "max( g, h ) = " << RST << ::max(g, h) << std::endl;
	std::cout << YELLOW << "***************************************" << RST << std::endl;
	
	return (0);
}