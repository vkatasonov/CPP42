/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scalar.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 12:41:10 by vkatason          #+#    #+#             */
/*   Updated: 2024/09/12 20:03:26 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <exception>
#include <limits>
#include <math.h>
#include <iomanip>

class Scalar
{
public:
	// Constructors
	Scalar(const std::string& string);
	Scalar(const Scalar& other);

	// Assignment operator overload
	Scalar& operator=(const Scalar& rhs);

	// Destructor
	~Scalar();

	char toChar() const;
	int toInt() const;
	float toFloat() const;
	double toDouble() const;

	class InvalidInput : public std::exception
	{
	public:
		const char* what() const throw()
		{
			return ("Invalid input");
		}
	};

	class Impossible : public std::exception
	{
	public:
		const char* what() const throw()
		{
			return ("Impossible");
		}
	};

	class NonDisplayable : public std::exception
	{
	public:
		const char* what() const throw()
		{
			return ("Non displayable");
		}
	};

private:

	const std::string&	_string;
	char				_charVal;
	int					_intVal;
	float				_floatVal;
	double				_doubleVal;
	enum scalarType {charType, intType, floatType, doubleType} _type;
};

std::ostream& operator<<(std::ostream& o, const Scalar& rhs);

/*
** ASCII colors escape sequences for printf
** Usage:
**      ft_printf(RED "Red bold text" RST);
**		ft_printf(B "Bold text goes here" RST);
*/
#define RST "\033[0m"					            /* Reset to default color */
#define BU "\033[1;4;0m"				            /* Bold and underlined text*/
#define B "\033[1m"						            /* Bold text default color */
#define U "\033[4m"						            /* Underlined text default color */
#define RED "\033[1;31m"				            /* Bold Red*/
#define GREEN "\033[1;32m"				            /* Bold Green */
#define YELLOW "\033[1;33m"				            /* Bold Yellow */
#define BLUE "\033[1;34m"				            /* Bold Blue */
#define MAGENTA "\033[1;35m"			            /* Bold Magenta */
#define CYAN "\033[1;36m"				            /* Bold Cyan */
#define WHITE "\033[1;37m"				            /* Bold White */
#define ORANGE "\033[1m\033[38;2;255;165;0m"	    /* Orange */
#define VIOLET "\033[1m\033[38;2;238;130;238m"	    /* Violet */
#define BG_BLACK "\033[40m"				            /* Background Black */
#define BG_GREEN "\033[42m"				            /* Background Green */
#define BG_YELLOW "\033[43m"			            /* Background Yellow */
#define BG_RED "\033[41m"				            /* Background Red */
#define BG_BLUE "\033[44m"				            /* Background Blue */
#define BG_MAGENTA "\033[45m"			            /* Background Magenta */
#define BG_CYAN "\033[46m"				            /* Background Cyan */
#define BG_WHITE "\033[47m"				            /* Background White */
#define BG_ORANGE "\033[48;2;255;165;0m"            /* Background Orange */
#define BG_VIOLET "\033[48;2;238;130;238m"          /* Background Violet */
#define BG_RESET "\033[49m"				            /* Background Reset */