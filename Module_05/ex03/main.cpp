/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 13:03:49 by vkatason          #+#    #+#             */
/*   Updated: 2024/09/06 14:37:16 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

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
    
    Intern intern;

	AForm* formA;
	AForm* formB;
	AForm* formC;
	AForm* formD;

	try
	{
		formA = intern.makeForm("shrubbery creation", "Earth");
		formB = intern.makeForm("robotomy request", "Marvin");
		formC = intern.makeForm("presidential pardon", "Beeblebrox Padron");
		formD = intern.makeForm("test", "test");
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RST << std::endl;
	}
    
    std::cout << YELLOW << "---------------------------------------------" << RST << std::endl;
    std::cout << *formA;
    std::cout << *formB;
    std::cout << *formC;
    std::cout << YELLOW << "---------------------------------------------" << RST<< std::endl;
    std::cout << YELLOW << "**********   EXEC SHRUBBERY FORM   **********" << RST<< std::endl;
    std::cout << YELLOW << "---------------------------------------------" << RST<< std::endl;
    Arthur.executeForm(*formA);
    Ford.executeForm(*formA);
    Zaphod.executeForm(*formA);
    std::cout << YELLOW << "---------------------------------------------" << RST<< std::endl;
    std::cout << YELLOW << "**********   EXEC ROBOTOMY FORM    **********" << RST<< std::endl;
    std::cout << YELLOW << "---------------------------------------------" << RST<< std::endl;
    Arthur.executeForm(*formB);
    Ford.executeForm(*formB);
    Zaphod.executeForm(*formB);
    std::cout << YELLOW << "---------------------------------------------" << RST<< std::endl;
    std::cout << YELLOW << "**********     EXEC PARDON FORM    **********" << RST<< std::endl;
    std::cout << YELLOW << "---------------------------------------------" << RST<< std::endl;
    Arthur.executeForm(*formC);
    Ford.executeForm(*formC);
    Zaphod.executeForm(*formC);
    std::cout << YELLOW << "---------------------------------------------" << RST<< std::endl;
    std::cout << YELLOW << "**********   SIGN SHRUBBERY FORM   **********" << RST<< std::endl;
    std::cout << YELLOW << "---------------------------------------------" << RST<< std::endl;
    Arthur.signForm(*formA);
    Ford.signForm(*formA);
    Zaphod.signForm(*formA);
    std::cout << YELLOW << "---------------------------------------------" << RST<< std::endl;
    std::cout << YELLOW << "**********   SIGN ROBOTOMY FORM    **********" << RST<< std::endl;
    std::cout << YELLOW << "---------------------------------------------" << RST<< std::endl;
    Arthur.signForm(*formB);
    Ford.signForm(*formB);
    Zaphod.signForm(*formB);
    std::cout << YELLOW << "---------------------------------------------" << RST<< std::endl;
    std::cout << YELLOW << "**********     SIGN PARDON FORM    **********" << RST<< std::endl;
    std::cout << YELLOW << "---------------------------------------------" << RST<< std::endl;
    Arthur.signForm(*formC);
    Ford.signForm(*formC);
    Zaphod.signForm(*formC);
    std::cout << YELLOW << "---------------------------------------------" << RST<< std::endl;
    std::cout << YELLOW << "**********   EXEC SHRUBBERY FORM   **********" << RST<< std::endl;
    std::cout << YELLOW << "---------------------------------------------" << RST<< std::endl;
    Arthur.executeForm(*formA);
    Ford.executeForm(*formA);
    Zaphod.executeForm(*formA);
    std::cout << YELLOW << "---------------------------------------------" << RST<< std::endl;
    std::cout << YELLOW << "**********   EXEC ROBOTOMY FORM    **********" << RST<< std::endl;
    std::cout << YELLOW << "---------------------------------------------" << RST<< std::endl;
    Arthur.executeForm(*formB);
    Ford.executeForm(*formB);
    Zaphod.executeForm(*formB);
    std::cout << YELLOW << "---------------------------------------------" << RST<< std::endl;
    std::cout << YELLOW << "**********     EXEC PARDON FORM    **********" << RST<< std::endl;
    std::cout << YELLOW << "---------------------------------------------" << RST<< std::endl;
    Arthur.executeForm(*formC);
    Ford.executeForm(*formC);
    Zaphod.executeForm(*formC);

    return (0);
}

