/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 16:15:24 by vkatason          #+#    #+#             */
/*   Updated: 2024/08/20 12:58:45 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

/**
 * @brief   Construct a new Brain:: Brain object
 * 
 * @note    The constructor initializes the Brain with 100 generic ideas
 *          that the dog or cat might have.
 * @note    genericIdeas[(std::rand() % genericIdeas->size())] is used to
 *          randomly select an idea from the genericIdeas array. 
 */
Brain::Brain()
{
    std::string genericIdeas[100] = {
    "I want to catch a mouse",
    "I want to take a nap",
    "I want to play with a ball",
    "I want to go for a walk",
    "I want to eat a treat",
    "I want to chase my tail",
    "I want to cuddle with my owner",
    "I want to explore the backyard",
    "I want to learn new tricks",
    "I want to groom myself",
    "I want to bark at the mailman",
    "I want to climb a tree",
    "I want to dig a hole",
    "I want to chase birds",
    "I want to fetch a stick",
    "I want to roll in the grass",
    "I want to sniff everything",
    "I want to stretch and yawn",
    "I want to sunbathe",
    "I want to wag my tail",
    "I want to watch TV",
    "I want to howl at the moon",
    "I want to play with other dogs",
    "I want to run around the house",
    "I want to sleep in my bed",
    "I want to swim in a pool",
    "I want to visit the vet",
    "I want to chase my shadow",
    "I want to eat my food",
    "I want to go for a car ride",
    "I want to hide under the bed",
    "I want to jump on the couch",
    "I want to lick my paws",
    "I want to nap in the sun",
    "I want to play with a frisbee",
    "I want to run in the park"    
    };
    
    for (int i = 0; i < 100; i++)
		this->_ideas[i] = genericIdeas[(std::rand() % genericIdeas->size())];
    std::cout << GREEN << "Brain was created" << std::endl;
}

Brain::Brain(const Brain &copy)             // Copy constructor
{
    for (int i = 0; i < 100; i++)
        this->_ideas[i] = copy._ideas[i];
    std::cout << YELLOW << "Brain was copied" << RST << std::endl;
}

Brain &Brain::operator=(const Brain &rhs)   // Assignment operator
{
    if (this == &rhs)
        return (*this);
    for (int i = 0; i < 100; i++)
        this->_ideas[i] = rhs._ideas[i];
    return (*this);
}

Brain::~Brain()                             // Destructor
{
    std::cout << RED << "Brain was destroyed" << RST << std::endl;
}

/**
 * @brief   Get idea at index
 *      
 * @return  The idea at the index passed as argument
 */
const std::string &Brain::getIdea(int index) const
{
    return (this->_ideas[index]);
}