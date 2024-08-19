/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 18:58:56 by vkatason          #+#    #+#             */
/*   Updated: 2024/08/19 17:06:45 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
  private:
	Brain *_brain; // Pointer to Brain object
  
  public:
	Cat();                            				// Default constructor
	Cat(std::string type);            				// Parametric constructor
	Cat(const Cat &copy);             				// Copy constructor
	Cat &operator=(const Cat &other); 				// Assignment operator
	~Cat();                           				// Destructor

	void makeSound() const; 						// Virtual function
	Brain* getBrain() const;						// Get Brain object
};

#endif