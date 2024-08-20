/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 22:34:23 by vkatason          #+#    #+#             */
/*   Updated: 2024/08/20 15:54:29 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iomanip>

int main()
{
	Animal* animals[6];
	int animalQuantity = sizeof(animals)/sizeof(animals[0]);
	
	for (int i = 0; i < animalQuantity; i++)
	{
		if (i >= (animalQuantity / 2))
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}
	
	for (int i = 0; i < animalQuantity; i++)
	{
		std::cout << BLUE << "Animal " << (i + 1) << " is: " << animals[i]->getType() << RST << std::endl;
		animals[i]->makeSound();
	}
	
	for (int i = 0; i < animalQuantity; i++)
	{
		delete animals[i];
	}
	return (0);
}