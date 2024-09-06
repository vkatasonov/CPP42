/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 15:21:41 by vkatason          #+#    #+#             */
/*   Updated: 2024/09/06 14:27:50 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include <fstream>

class PresidentialPardonForm : public AForm
{
  private:
    PresidentialPardonForm();

  public:
    /* Parametrized constructor */
    PresidentialPardonForm(const std::string &target);
    
    /* Copy constructor*/
    PresidentialPardonForm(const PresidentialPardonForm &copy);
    
    /* Assignment overload */
    PresidentialPardonForm &operator=(const PresidentialPardonForm &rhs);

    /* Default destructor */
    ~PresidentialPardonForm();

    /* Function that executes the form */
    void execute(Bureaucrat const &bureaucrat) const;
};