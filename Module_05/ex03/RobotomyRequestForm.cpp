/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 14:50:58 by vkatason          #+#    #+#             */
/*   Updated: 2024/09/06 14:43:00 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("robotomy request", "default",
    72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("robotomy request",
    target, 72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm(copy)
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs)
{
    if (this == &rhs)
        return (*this);
    this->AForm::operator=(rhs);
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void RobotomyRequestForm::execute(const Bureaucrat &bureaucrat) const
{
    this->formExec(bureaucrat);
    std::cout << ORANGE << "Makes some drilling noises!" << RST << std::endl;
    std::cout << ORANGE << "Bzzzz... Bzzzz... Bzzzz..." << RST << std::endl;
    
    // Seed the random number generator to produce random results
    std::srand(std::time(NULL));
    
    // Determine success or failure of robotomization
    if (rand() < RAND_MAX / 2)
    {
        std::cout << GREEN << this->getTarget() << " has been robotomized successfully!" << RST << std::endl;
    }
    else
    {
        std::cout << RED << "The robotomy request failed on " << this->getTarget() << "." << RST << std::endl;
    }
}

