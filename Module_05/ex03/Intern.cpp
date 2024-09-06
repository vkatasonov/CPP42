/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 12:46:56 by vkatason          #+#    #+#             */
/*   Updated: 2024/09/06 14:30:58 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern()
{
}
Intern::Intern(const Intern &copy)
{
    (void)copy;
}
Intern &Intern::operator=(const Intern &rhs)
{
	if (this == &rhs)
		return (*this);
	Intern::operator=(rhs);
	return (*this);
}
Intern::~Intern()
{
}

AForm *Intern::makeForm(const std::string &formName, const std::string &target)
{
	std::string formsName[] = {"shrubbery creation", "robotomy request",
		"presidential pardon"};
    int i = 0;
    while (i < 3 && formName != formsName[i])
        i++;
    AForm *tmp = NULL;
    switch (i)
    {
        case 0:
        tmp = new ShrubberyCreationForm(target);
        break;
        case 1:
        tmp = new RobotomyRequestForm(target);
        break;
        case 2:
        tmp = new PresidentialPardonForm(target);
        break;
        default:
        throw Intern::InvalidFormException();
        break;
   }  
   std::cout << GREEN << "Intern creates " << formName << RST << std::endl;
   return (tmp);
}
   