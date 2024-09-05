/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 13:03:49 by vkatason          #+#    #+#             */
/*   Updated: 2024/09/05 17:23:04 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() 
{
    Bureaucrat Arthur("Arthur", 135);
    Bureaucrat Ford("Ford", 50);
    Bureaucrat Zaphod("Zaphod", 1);

    std::cout << Arthur;
    std::cout << Ford; 
    std::cout << Zaphod;
    ShrubberyCreationForm shrub("Earth");
    PresidentialPardonForm pardon("Beeblebrox Padron");
    RobotomyRequestForm robotomy("Marvin");
    std::cout << YELLOW << "---------------------------------------------" << RST<< std::endl;
    std::cout << shrub;
    std::cout << pardon;
    std::cout << robotomy;
    std::cout << YELLOW << "---------------------------------------------" << RST<< std::endl;
    std::cout << YELLOW << "**********   EXEC SHRUBBERY FORM   **********" << RST<< std::endl;
    std::cout << YELLOW << "---------------------------------------------" << RST<< std::endl;
    Arthur.executeForm(shrub);
    Ford.executeForm(shrub);
    Zaphod.executeForm(shrub);
    std::cout << YELLOW << "---------------------------------------------" << RST<< std::endl;
    std::cout << YELLOW << "**********   EXEC ROBOTOMY FORM    **********" << RST<< std::endl;
    std::cout << YELLOW << "---------------------------------------------" << RST<< std::endl;
    Arthur.executeForm(robotomy);
    Ford.executeForm(robotomy);
    Zaphod.executeForm(robotomy);
    std::cout << YELLOW << "---------------------------------------------" << RST<< std::endl;
    std::cout << YELLOW << "**********     EXEC PARDON FORM    **********" << RST<< std::endl;
    std::cout << YELLOW << "---------------------------------------------" << RST<< std::endl;
    Arthur.executeForm(pardon);
    Ford.executeForm(pardon);
    Zaphod.executeForm(pardon);
    std::cout << YELLOW << "---------------------------------------------" << RST<< std::endl;
    std::cout << YELLOW << "**********   SIGN SHRUBBERY FORM   **********" << RST<< std::endl;
    std::cout << YELLOW << "---------------------------------------------" << RST<< std::endl;
    Arthur.signForm(shrub);
    Ford.signForm(shrub);
    Zaphod.signForm(shrub);
    std::cout << YELLOW << "---------------------------------------------" << RST<< std::endl;
    std::cout << YELLOW << "**********   SIGN ROBOTOMY FORM    **********" << RST<< std::endl;
    std::cout << YELLOW << "---------------------------------------------" << RST<< std::endl;
    Arthur.signForm(robotomy);
    Ford.signForm(robotomy);
    Zaphod.signForm(robotomy);
    std::cout << YELLOW << "---------------------------------------------" << RST<< std::endl;
    std::cout << YELLOW << "**********     SIGN PARDON FORM    **********" << RST<< std::endl;
    std::cout << YELLOW << "---------------------------------------------" << RST<< std::endl;
    Arthur.signForm(pardon);
    Ford.signForm(pardon);
    Zaphod.signForm(pardon);
    std::cout << YELLOW << "---------------------------------------------" << RST<< std::endl;
    std::cout << YELLOW << "**********   EXEC SHRUBBERY FORM   **********" << RST<< std::endl;
    std::cout << YELLOW << "---------------------------------------------" << RST<< std::endl;
    Arthur.executeForm(shrub);
    Ford.executeForm(shrub);
    Zaphod.executeForm(shrub);
    std::cout << YELLOW << "---------------------------------------------" << RST<< std::endl;
    std::cout << YELLOW << "**********   EXEC ROBOTOMY FORM    **********" << RST<< std::endl;
    std::cout << YELLOW << "---------------------------------------------" << RST<< std::endl;
    Arthur.executeForm(robotomy);
    Ford.executeForm(robotomy);
    Zaphod.executeForm(robotomy);
    std::cout << YELLOW << "---------------------------------------------" << RST<< std::endl;
    std::cout << YELLOW << "**********     EXEC PARDON FORM    **********" << RST<< std::endl;
    std::cout << YELLOW << "---------------------------------------------" << RST<< std::endl;
    Arthur.executeForm(pardon);
    Ford.executeForm(pardon);
    Zaphod.executeForm(pardon);

    return (0);
}

