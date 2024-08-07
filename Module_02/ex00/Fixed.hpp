/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 02:52:42 by vkatason          #+#    #+#             */
/*   Updated: 2024/08/07 05:17:12 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

class Fixed
{
  private:
	int _raw_bits;
	static const int _bits = 8;

  public:
	Fixed();                            // default constructor
	Fixed(const Fixed &copy);           // copy constructor
	Fixed &operator=(const Fixed &src); // assignation operator overload
	~Fixed();                           // destructor

	// returns the raw value of the fixed point value
	int getRawBits(void) const;

	// sets the raw value of the fixed point value
	void setRawBits(int const raw);
};

/*
** ASCII colors escape sequences for printf
** Usage:
**      ft_printf(RED "Red bold text" RST);
**		ft_printf(B "Bold text goes here" RST);
*/
# define RST "\033[0m" /* Reset to default color */
# define BU "\033[1;4;0m" /* Bold and underlined text*/
# define B "\033[1m" /* Bold text default color */
# define U "\033[4m" /* Underlined text default color */
# define RED "\033[1;31m" /* Bold Red*/
# define GREEN "\033[1;32m" /* Bold Green */
# define YELLOW "\033[1;33m" /* Bold Yellow */
# define BLUE "\033[1;34m" /* Bold Blue */
# define MAGENTA "\033[1;35m" /* Bold Magenta */
# define CYAN "\033[1;36m" /* Bold Cyan */
# define WHITE "\033[1;37m" /* Bold White */
# define ORANGE "\033[38;2;255;165;0m" /* Orange */
# define VIOLET "\033[38;2;238;130;238m" /* Violet */
# define BG_BLACK "\033[40m" /* Background Black */
# define BG_GREEN "\033[42m" /* Background Green */
# define BG_YELLOW "\033[43m" /* Background Yellow */
# define BG_RED "\033[41m" /* Background Red */
# define BG_BLUE "\033[44m" /* Background Blue */
# define BG_MAGENTA "\033[45m" /* Background Magenta */
# define BG_CYAN "\033[46m" /* Background Cyan */
# define BG_WHITE "\033[47m" /* Background White */
# define BG_ORANGE "\033[48;2;255;165;0m" /* Background Orange */
# define BG_VIOLET "\033[48;2;238;130;238m" /* Background Violet */

#endif
