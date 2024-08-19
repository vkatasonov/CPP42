/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 22:34:23 by vkatason          #+#    #+#             */
/*   Updated: 2024/08/19 15:32:15 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	const Animal		*meta = new Animal();
	const Animal		*j = new Dog("Pastor Aleman");
	const Animal		*i = new Cat("Persa");
	const WrongAnimal	*f = new WrongCat();
	const WrongCat		*dirtyKitty = new WrongCat("ChiHuaHua");

	std::cout << ORANGE << meta->getType() << " " << std::endl;
    meta->makeSound();                                             // Will output the animal sound!
	std::cout << ORANGE << i->getType() << " " << std::endl;
	i->makeSound();                                                // Will output the cat sound!
	std::cout << ORANGE << j->getType() << " " << std::endl;
	j->makeSound();                                                // Will output the dog sound!
    std::cout << ORANGE << f->getType() << " " << std::endl;
	f->makeSound();                                                // Will output the wrong animal sound!
    std::cout << ORANGE << dirtyKitty->getType() << " " << std::endl;
	dirtyKitty->makeSound();                                       // Will output the wrong cat sound!
    
	
    delete meta;
	delete j;
	delete i;
	delete f;
	delete dirtyKitty;
	return (0);
}
