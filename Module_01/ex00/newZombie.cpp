/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 15:47:04 by vkatason          #+#    #+#             */
/*   Updated: 2024/07/19 12:15:48 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/**
 * @brief       Function creates a new Zombie on the heap.
 */
Zombie* newZombie( std::string name )
{
    return new Zombie( name );
}
