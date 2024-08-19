/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 18:58:45 by vkatason          #+#    #+#             */
/*   Updated: 2024/08/19 13:34:59 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog : public Animal
{
    public:
        Dog();                                 // Default constructor
        Dog(std::string type);                 // Parametric constructor
        Dog(const Dog &copy);                  // Copy constructor
        Dog &operator=(const Dog &other);      // Assignment operator
        ~Dog();                                // Destructor
        
        void makeSound() const;                // Virtual function
};

#endif