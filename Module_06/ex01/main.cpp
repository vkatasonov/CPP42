/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 11:48:33 by vkatason          #+#    #+#             */
/*   Updated: 2024/09/13 15:57:59 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
	Data input;

	input.name = "Bill";
	input.surname = "Gates";
	input.age = 65;
	input.height = 154.55;

	std::cout << BLUE << "Input data:" << RST << std::endl; 
    std::cout << YELLOW << "Name: " << RST << input.name << std::endl;
	std::cout << YELLOW << "Surname: " << RST << input.surname << std::endl;
	std::cout << YELLOW << "Age: " << RST << input.age << std::endl;
	std::cout << YELLOW << "Height: " << RST << input.height << std::endl;
    std::cout << std::endl;
    
	uintptr_t output_uintptr = Serializer::serialize(&input);
    std::cout << BLUE << "Input address (uintptr): " << output_uintptr << std::endl;
    std::cout << std::endl;
	
    Data* output = Serializer::deserialize(output_uintptr);
    std::cout << BLUE << "Output data:"<< RST << std::endl;
    std::cout << YELLOW << "Name: " << RST << output->name << std::endl;
    std::cout << YELLOW << "Surname: " << RST << output->surname << std::endl;
    std::cout << YELLOW << "Age: " << RST << output->age << std::endl;
    std::cout << YELLOW << "Height: " << RST << output->height << std::endl;
	std::cout << BLUE << std::setfill('-') << "" << std::endl; 
} 