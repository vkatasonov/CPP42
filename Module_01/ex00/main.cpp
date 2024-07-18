/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 16:17:15 by vkatason          #+#    #+#             */
/*   Updated: 2024/07/18 16:48:17 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    Zombie z1( "inStack Zombie" );
    Zombie* z2 = newZombie( "inHeap Zombie" );
    z1.announce();
    z2->announce();
    randomChump( "inRandomChumpStack" );
    delete z2; 
}