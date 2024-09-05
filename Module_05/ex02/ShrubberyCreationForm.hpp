/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShruberryCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:28:46 by vkatason          #+#    #+#             */
/*   Updated: 2024/09/05 16:45:16 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"
#include <fstream>


class ShrubberyCreationForm : public AForm
{
  private:
	ShrubberyCreationForm();

  public:
    /* Parametrized constructor */
    ShrubberyCreationForm(const std::string &target);
    
    /* Copy constructor*/
    ShrubberyCreationForm(const ShrubberyCreationForm &copy);
    
    /* Assignment overload */
    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &rhs);

    /* Default destructor */
    ~ShrubberyCreationForm();

    /* Function that executes the form */
    void execute(Bureaucrat const &bureaucrat) const;
};