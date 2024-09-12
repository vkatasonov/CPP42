/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scalar.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 13:40:13 by vkatason          #+#    #+#             */
/*   Updated: 2024/09/12 20:03:14 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Scalar.hpp"

Scalar::Scalar(const std::string& string)
	: _string(string)
{
	if (string.empty())
		throw Scalar::InvalidInput();
	else if (string.size() == 1)
	{
		if (isdigit(string[0]))
		{
			this->_intVal = static_cast<int>(strtol(string.c_str(), NULL, 10));
			this->_type = intType;
		}
		else
		{
			this->_charVal = string[0];
			this->_type = charType;
		}
	}
	else
	{
		char *longRest;
		long longPart = strtol(string.c_str(), &longRest, 10);
		char *doubleRest;
		double doublePart = strtof(string.c_str(), &doubleRest);

		if (*longRest)
		{
			if (*doubleRest)
			{
				if (*doubleRest == 'f')
				{
					this->_floatVal = static_cast<float>(doublePart);
					this->_type = floatType;
				}
				else
					throw Scalar::InvalidInput();
			}
			else
			{
				this->_doubleVal = doublePart;
				this->_type = doubleType;
			}
		}
		else
		{
			if (longPart > std::numeric_limits<int>::max() || longPart < std::numeric_limits<int>::min())
				throw Scalar::InvalidInput();
			else
			{
				this->_intVal = static_cast<int>(longPart);
				this->_type = intType;
			}
		}
	}
}

Scalar::~Scalar()
{
}

char Scalar::toChar() const
{
	switch (this->_type)
	{
	char c;
	case charType:
		return this->_charVal;
	case intType:
		c = static_cast<char>(this->_intVal);
		if (!isprint(c))
			throw Scalar::NonDisplayable();
		else
			return c;
	case floatType:
		c = static_cast<char>(this->_floatVal);
		if (isnan(this->_floatVal) || isinf(this->_floatVal)
			|| this->_floatVal > std::numeric_limits<char>::max() || this->_floatVal < std::numeric_limits<char>::min())
			throw Scalar::Impossible();
		else if (!isprint(c))
			throw Scalar::NonDisplayable();
		else
			return c;
	case doubleType:
		c = static_cast<char>(this->_doubleVal);
		if (isnan(this->_doubleVal) || isinf(this->_doubleVal)
			|| this->_doubleVal > std::numeric_limits<char>::max() || this->_doubleVal < std::numeric_limits<char>::min())
			throw Scalar::Impossible();
		else if (!isprint(c))
			throw Scalar::NonDisplayable();
		else
			return c;
	default:
		break;
	}
}

int Scalar::toInt() const
{
	switch (this->_type)
	{
	case charType:
		return static_cast<int>(this->_charVal);
	case intType:
		return this->_intVal;
	case floatType:
		if (isnan(this->_floatVal) || isinf(this->_floatVal)
			|| static_cast<int>(this->_floatVal) > std::numeric_limits<int>::max() || static_cast<int>(this->_floatVal) < std::numeric_limits<int>::min())
			throw Scalar::Impossible();
		else
			return static_cast<int>(this->_floatVal);
	case doubleType:
		if (isnan(this->_doubleVal) || isinf(this->_doubleVal)
			|| this->_doubleVal > std::numeric_limits<int>::max() || this->_doubleVal < std::numeric_limits<int>::min())
			throw Scalar::Impossible();
		else
			return static_cast<int>(this->_doubleVal);
	default:
		break;
	}
}

float Scalar::toFloat() const
{
	switch (this->_type)
	{
	case charType:
		return static_cast<float>(this->_charVal);
	case intType:
		return static_cast<float>(this->_intVal);
	case floatType:
		return this->_floatVal;
	case doubleType:
		return static_cast<float>(this->_doubleVal);
	default:
		break;
	}
}

double Scalar::toDouble() const
{
	switch (this->_type)
	{
	case charType:
		return static_cast<double>(this->_charVal);
	case intType:
		return static_cast<double>(this->_intVal);
	case floatType:
		return static_cast<double>(this->_floatVal);
	case doubleType:
		return this->_doubleVal;
	default:
		break;
	}
}

std::ostream& operator<<(std::ostream& o, const Scalar& rhs)
{
	o << YELLOW << "char: " << RST;
	try
	{
		char c;
		c = rhs.toChar();
		o << BLUE << "'" << c << "'" << RST << std::endl;
	}
	catch(const std::exception& e)
	{
		o << RED << e.what() << RST << std::endl;
	}
	o << YELLOW << "int: " << RST;
	try
	{
		int i;
		i = rhs.toInt();
		o << BLUE << i << RST << std::endl;
	}
	catch(const std::exception& e)
	{
		o << RED << e.what() << RST << std::endl;
	}
	o << YELLOW << "float: " << RST;
	try
	{
		float f;
		f = rhs.toFloat();
		double intPart;
		if (modf(f, &intPart) == 0)
			o.precision(1);
		o << BLUE << std::fixed << f << "f" << RST << std::endl;
	}
	catch(const std::exception& e)
	{
		o << RED << e.what() << RST << std::endl;
	}
	o << YELLOW << "double: " << RST;
	try
	{
		double d;
		d = rhs.toDouble();
		double intPart;
		if (modf(d, &intPart) == 0)
			o.precision(1);
		o << BLUE << std::fixed << d << RST << std::endl;
	}
	catch(const std::exception& e)
	{
		o << RED << e.what() << RST << std::endl;
	}
	return o;
}