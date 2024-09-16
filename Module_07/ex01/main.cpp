/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 15:38:55 by vkatason          #+#    #+#             */
/*   Updated: 2024/09/16 16:35:17 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void	floatToInt(float const &f)
{
	std::cout << BLUE << static_cast<int>(f) << " " << RST;
}

void	stringToPascaleCase(const std::string &str)
{
	std::string pascale_case;
	for (size_t i = 0; i < str.length(); i++)
	{
		if (i == 0 || str[i - 1] == '_')
			pascale_case += toupper(str[i]);
		else if (str[i] != '_')
			pascale_case += tolower(str[i]);
	}
	std::cout << BLUE << pascale_case << RST;
}

void	stringToUpperCase(const std::string &str)
{
	std::string upper_case;
	for (size_t i = 0; i < str.length(); i++)
		upper_case += toupper(str[i]);
	std::cout << BLUE << upper_case << " "<< RST;
}

void	stringToLowerCase(const std::string &str)
{
	std::string lower_case;
	for (size_t i = 0; i < str.length(); i++)
		lower_case += tolower(str[i]);
	std::cout << BLUE << lower_case << " " << RST;
}

void	doubleToFloat(double const &d)
{
	std::cout << BLUE << static_cast<int>(d) << " " << RST;
}

void	intToChar(int const &i)
{
	std::cout << BLUE << static_cast<char>(i) << " " << RST;
}

int	main(void)
{
	std::string str[] = {"hello", "world", "this", "is", "a", "test"};
    int i[] = {65, 66, 67, 68, 69};
    float f[] = {1.1, 2.22, 3.333, 4.4444, 5.55555};
    double d[] = {1.1, 2.2, 3.3, 4.4, 5.5};

    std::cout << YELLOW << "************ String array *************" << RST << std::endl;
    ::iter(str, 6, print<std::string>);
    ::iter(str, 6, stringToPascaleCase);
    ::iter(str, 6, stringToUpperCase);
    ::iter(str, 6, stringToLowerCase);

    std::cout << YELLOW << "************* Int array ***************" << RST << std::endl;
    ::iter(i, 5, print<int>);
    ::iter(i, 5, intToChar);
    
    std::cout << YELLOW << "************ Float array **************" << RST << std::endl;
    ::iter(f, 5, print<float>);
    ::iter(f, 5, floatToInt);
    
    std::cout << YELLOW << "*********** Double array **************" << RST << std::endl;
    ::iter(d, 5, print<double>);
    ::iter(d, 5, doubleToFloat);
    
    return (0);
}