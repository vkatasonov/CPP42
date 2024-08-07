/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 12:32:22 by vkatason          #+#    #+#             */
/*   Updated: 2024/07/19 13:05:12 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/**
 * @brief			Main function that creates 
 * 					a Zombie horde gives them names,
 * 					makes them announce and then 
 * 					deletes the horde.  
 * @note			The app uses N as a constant
 * 					to define the number of Zombies
 * 					(as recomended in the 42 videos).      
 * 
 * @return int 
 */
int main()
{
	int const N = 42;
	Zombie *zombies = zombieHorde(N, "42_ZombieHorde");
	for (int i = 0; i < N; i++)
		zombies[i].announce();
	delete[] zombies;
	return 0;
}
