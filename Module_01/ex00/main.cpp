/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 16:17:15 by vkatason          #+#    #+#             */
/*   Updated: 2024/07/19 12:20:03 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/**
 * @brief   App creates a new Zombie
 *          on the heap, on the stack
 *          and inside the stack of 
 * 			the randomChump function.
 * 
 * note     App creates a new Zombie (z2) on the heap,
 * 			so it must be deleted to avoid memory leaks.
 */
int main()
{
	Zombie z1( "inStack Zombie" );
	Zombie* z2 = newZombie( "inHeap Zombie" );
	z1.announce();
	z2->announce();
	randomChump( "inRandomChumpStack" );
	delete z2;
}