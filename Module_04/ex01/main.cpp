/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 22:34:23 by vkatason          #+#    #+#             */
/*   Updated: 2024/08/19 18:39:50 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	}
	
	Cat copy(*(Cat *)animals[0]);
	Dog copy2(*(Dog *)animals[3]);
	std::cout << std::endl;
		
	// Print header
    std::cout << std::setw(10) << std::left << "Brain"
			<< " | " << std::setw(30) << std::left << copy.getType()
            << " | " << std::setw(30) << std::left << copy2.getType()
            << std::endl;
    std::cout << std::string(80, '-') << std::endl;

    // Print ideas for each brain
    for (int i = 0; i < 10; i++)
    {
        std::cout << std::setw(10) << std::left << ("idea ") << i
                  << " | " << std::setw(30) << std::left << copy.getBrain()->getIdea(i)
                  << " | " << std::setw(30) << std::left << copy.getBrain()->getIdea(i)
                  << std::endl;
        std::cout << std::string(80, '-') << std::endl;
    }
	std::cout << std::endl;
	for (int i = 0; i < animalQuantity; i++)
	{
		delete animals[i];
	}
	return (0);
}