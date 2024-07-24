/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 11:35:04 by vkatason          #+#    #+#             */
/*   Updated: 2024/07/24 16:14:44 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/**
 * @brief 				    Helper function converts an integer to a string
 * 						    by using the modulo operator and the division operator.
 * 						    Had to be implemented because std::to_string is not
 * 						    available in the C++98 standard.
 *  
 * @param number 		    Integer to convert.
 * @return std::string 	    String representation of the integer.
 */
std::string intToString(int number)
{
    if (number == 0) return "0";
    std::string result;
	bool isNegative = number < 0;
    if (isNegative) number = -number;
    while (number > 0) 
	{
        result.insert(result.begin(), '0' + (number % 10));
        number /= 10;
    }
    if (isNegative) result.insert(result.begin(), '-');
    return result;
}


/**
 * @brief 				Function creates a new
 * 						Zombie horde on the heap.
 * 
 * @param N 			Number of Zombies in the horde.
 * @param name 			Name of the horde of Zombies.
 * @return Zombie* 		Pointer to the first Zombie in the horde.
 * 
 * @note 				To create a Zombie horde using default
 * 						constructor. To set the name of each Zombie
 * 						in the horde, the function uses the setName
 * 						method of the Zombie class.
 * 						For debugging purposes, the function prints
 * 						a message to the console when a Zombie is created.
 */
Zombie* zombieHorde( int N, std::string name )
{
    Zombie *zombies = new Zombie[N];

	for (int i = 0; i < N; i++)
	{
        zombies[i].setName(name + "_" + intToString(i + 1));
		std::cout << WHITE << BG_GREEN << std::setw(20) << std::left << " " + zombies[i].getName() + ":" << "is created " RST << std::endl;
	}
	return zombies;
}