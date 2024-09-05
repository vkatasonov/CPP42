/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 14:50:37 by vkatason          #+#    #+#             */
/*   Updated: 2024/09/05 16:26:42 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"
#include <fstream>
#include <ctime>
#include <cstdlib>

class RobotomyRequestForm : public AForm
{
  private:
    RobotomyRequestForm();

  public:
    /* Parametrized constructor */
    RobotomyRequestForm(const std::string &target);
    
    /* Copy constructor*/
    RobotomyRequestForm(const RobotomyRequestForm &copy);
    
    /* Assignment overload */
    RobotomyRequestForm &operator=(const RobotomyRequestForm &rhs);

    /* Default destructor */
    ~RobotomyRequestForm();

    /* Function that executes the form */
    void execute(Bureaucrat const &bureaucrat) const;
};