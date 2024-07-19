/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 11:35:04 by vkatason          #+#    #+#             */
/*   Updated: 2024/07/19 12:48:18 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

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
		zombies[i].setName(name + "_" + std::to_string(i + 1));
		std::cout << WHITE << BG_GREEN << std::setw(20) << std::left << " " + zombies[i].getName() + ":" << "is created " RST << std::endl;
	}
	return zombies;
}