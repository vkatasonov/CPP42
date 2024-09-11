/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 13:40:13 by vkatason          #+#    #+#             */
/*   Updated: 2024/09/11 13:49:00 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(std::string &str) : _str(str)
{
    // Check if the string is empty
    if (str.empty())
        throw ScalarConverter::InalidInputException();
    // Handle the case of a char
    else if (str.size() == 1)
    {
        
    }
}