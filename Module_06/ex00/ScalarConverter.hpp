/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 12:41:10 by vkatason          #+#    #+#             */
/*   Updated: 2024/09/11 14:37:04 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <exception>
#include <limits>
#include <iomanip>
#include <cmath>

class ScalarConverter
{
  private:
	std::string _str;
	char _charValue;
	int _intValue;
	float _floatValue;
	double _doubleValue;
	enum	Type
	{
		CHAR,
		INT,
		FLOAT,
		DOUBLE
	} _type;

  public:
	// Default constructor
	ScalarConverter(std::string &str);

	// Copy constructor
	ScalarConverter(const ScalarConverter &other);

	// Assignment operator overload
	ScalarConverter &operator=(const ScalarConverter &rhs);

	// Destructor
	~ScalarConverter();

	// Exception inner classes

	class InalidInputException : public std::exception
	{
		public:
		const char *what() const throw()
		{
			return ("Invalid input");
		}
	};

	class ImpossibleException : public std::exception
	{
		public:
		const char *what() const throw()
		{
			return ("Impossible to proceed conversion");
		}
	};

	class NonDisplayableException : public std::exception //Serves for unprintable characters
	{
		public:
		const char *what() const throw()
		{
			return ("Non displayable");
		}
	};

    //Converter functions
    
    char toChar() const;
    int toInt() const;
    float toFloat() const;
    double toDouble() const;
};
    //Overload << operator
std::ostream& operator<<(std::ostream& o, const Scalar& rhs);



    