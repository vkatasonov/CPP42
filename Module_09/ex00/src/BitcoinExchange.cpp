/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 10:37:47 by vkatason          #+#    #+#             */
/*   Updated: 2024/09/27 14:01:00 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

unsigned int	strToUI(const std::string &str)
{
	unsigned int	result;

	std::stringstream ss(str);
	ss >> result;
	return (result);
}

double	strToDouble(const std::string &str)
{
	double	result;

	std::stringstream ss(str);
	ss >> result;
	return (result);
}

BitcoinExchange::BitcoinExchange()
{
	unsigned int	dateInt;

	this->_dataFile.open(DATAFILE);
	if (!this->_dataFile.is_open())
	{
		throw std::runtime_error(RED "data.csv not found" RST);
	}
	{
		std::string firstLine;
		std::getline(this->_dataFile, firstLine);
		if (firstLine != "date,exchange_rate")
		{
			throw std::runtime_error(RED "Invalid data.csv format" RST);
		}
	}
	{
		std::string line;
		while (getline(this->_dataFile, line))
		{
			std::stringstream ss(line);
			std::string date;
			std::string exchangeRate;
			std::getline(ss, date, ',');
            //Pasre Date to int
			date = date.substr(0, 4) + date.substr(5, 2) + date.substr(8, 2);
			dateInt = strToUI(date);
			std::getline(ss, exchangeRate, ',');
			this->_dataBase[dateInt] = strToDouble(exchangeRate);
		}
	}
	this->_dataFile.close();
}

double BitcoinExchange::getExchangeRate(const std::string &date) const
{
	unsigned int dateInt = strToUI(date.substr(0, 4) + date.substr(5, 2) + date.substr(8, 2));

	try
	{
		return (this->_dataBase.at(dateInt));
	}
	catch (std::out_of_range &e)
	{
		while (dateInt > 0)
		{
			dateInt--;
			try
			{
				return (this->_dataBase.at(dateInt));
			}
			catch (std::out_of_range &e)
			{
				continue ;
			}
		}
	}
	return (0);
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &rhs)
{
	if (this != &rhs)
	{
		this->_dataBase = rhs._dataBase;
	}
	return (*this);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy) : _dataFile()
{
	*this = copy;
}

BitcoinExchange::~BitcoinExchange()
{
    this->_dataBase.clear();
}
