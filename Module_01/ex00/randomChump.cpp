/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 15:47:33 by vkatason          #+#    #+#             */
/*   Updated: 2024/07/19 12:17:55 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/**
 * @brief           Function creates a new
 *                  Zombie on the stack.
 * 
 * @param name      Name of the Zombie
 *                  passed as a parameter.
 * 
 * @note            Function creates a new
 *                  Zombie on the stack and     
 *                  makes him announce itself
 *                  using the announce method.
 */
void randomChump( std::string name )
{
    Zombie zombie(name);
    zombie.announce();
}