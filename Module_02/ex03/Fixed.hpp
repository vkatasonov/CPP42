/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 02:52:42 by vkatason          #+#    #+#             */
/*   Updated: 2024/08/07 16:41:26 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>
#include <cmath>

/*
** ASCII colors escape sequences for printf
** Usage:
**      ft_printf(RED "Red bold text" RST);
**		ft_printf(B "Bold text goes here" RST);
*/
#define RST "\033[0m"					   /* Reset to default color */
#define BU "\033[1;4;0m"				   /* Bold and underlined text*/
#define B "\033[1m"						   /* Bold text default color */
#define U "\033[4m"						   /* Underlined text default color */
#define RED "\033[1;31m"				   /* Bold Red*/
#define GREEN "\033[1;32m"				   /* Bold Green */
#define YELLOW "\033[1;33m"				   /* Bold Yellow */
#define BLUE "\033[1;34m"				   /* Bold Blue */
#define MAGENTA "\033[1;35m"			   /* Bold Magenta */
#define CYAN "\033[1;36m"				   /* Bold Cyan */
#define WHITE "\033[1;37m"				   /* Bold White */
#define ORANGE "\033[38;2;255;165;0m"	   /* Orange */
#define VIOLET "\033[38;2;238;130;238m"	   /* Violet */
#define BG_BLACK "\033[40m"				   /* Background Black */
#define BG_GREEN "\033[42m"				   /* Background Green */
#define BG_YELLOW "\033[43m"			   /* Background Yellow */
#define BG_RED "\033[41m"				   /* Background Red */
#define BG_BLUE "\033[44m"				   /* Background Blue */
#define BG_MAGENTA "\033[45m"			   /* Background Magenta */
#define BG_CYAN "\033[46m"				   /* Background Cyan */
#define BG_WHITE "\033[47m"				   /* Background White */
#define BG_ORANGE "\033[48;2;255;165;0m"   /* Background Orange */
#define BG_VIOLET "\033[48;2;238;130;238m" /* Background Violet */

class Fixed
{
private:
	int _raw_bits;
	static const int _bits = 8;

public:
	Fixed();				  // default constructor
	Fixed(int const value);	  // parameterized constructor (with int value)
	Fixed(float const value); // parameterized constructor (with float value)
	Fixed(const Fixed &copy); // copy constructor
	~Fixed();				  // destructor

	/* Operator overloads */
	Fixed &operator=(const Fixed &src); // assignation operator overload
	Fixed operator+(const Fixed &src);	// addition operator overload
	Fixed operator-(const Fixed &src);	// subtraction operator overload
	Fixed operator*(const Fixed &src);	// multiplication operator overload
	Fixed operator/(const Fixed &src);	// division operator overload

	/* Comparison operators */
	bool operator>(const Fixed &src);  // greater than operator overload
	bool operator<(const Fixed &src);  // less than operator overload
	bool operator>=(const Fixed &src); // greater than or equal to operator overload
	bool operator<=(const Fixed &src); // less than or equal to operator overload
	bool operator==(const Fixed &src); // equal to operator overload
	bool operator!=(const Fixed &src); // not equal to operator overload

	/* Increment and decrement operators */
	Fixed &operator++();   // pre-increment operator overload
	Fixed &operator--();   // pre-decrement operator overload
	Fixed operator++(int); // post-increment operator overload
	Fixed operator--(int); // post-decrement operator overload

	/* Getter and setter functions */
	int getRawBits(void) const;		// returns the raw value of the fixed point value
	void setRawBits(int const raw); // sets the raw value of the fixed point value

	/* Conversion functions */
	int toInt(void) const;	   // returns the fixed point value as an integer
	float toFloat(void) const; // returns the fixed point value as a float

	/* Comparison functions with two parameters passed 
	 * as references to constant fixed-point numbers */

	/**
	 * @brief 		A static member function max
	 * 				that takes as parameters two
	 * 				references to constant
	 * 				fixed-point numbers,
	 * 				and returns a reference
	 * 				to the greatest one
	 */
	static const Fixed &max(const Fixed &a, const Fixed &b);

	/**
	 * @brief 		A static member function min
	 * 				that takes as parameters two
	 * 				references to constant
	 * 				fixed-point numbers,
	 * 				and returns a reference
	 * 				to the smallest one
	 */
	static const Fixed &min(const Fixed &a, const Fixed &b);

	/* Comparison functions with two parameters passed 
	 * as references to fixed-point numbers */

	/**
	 * @brief 		A static member function max
	 * 				that takes as parameters two
	 * 				references on fixed-point numbers,
	 * 				and returns a reference to the greatest one
	 */
	static Fixed &max(Fixed &a, Fixed &b);

	/**
	 * @brief 		A static member function min
	 * 				that takes as parameters two
	 * 				references on fixed-point numbers,
	 * 				and returns a reference to the smallest one
	 */
	static Fixed &min(Fixed &a, Fixed &b);
};

/* Insertion (<<) operator overload
 * that inserts a floating-point representation
 * of the fixed-point number into
 * the output stream object passed as parameter
 */
std::ostream &operator<<(std::ostream &o, const Fixed &fixed);

#endif
