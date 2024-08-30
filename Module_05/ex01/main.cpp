/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 13:03:49 by vkatason          #+#    #+#             */
/*   Updated: 2024/08/30 16:51:27 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    Bureaucrat Paco("Paco", 1);
    Bureaucrat Alicia("Alicia", 150);
    Form form1("Form 1");
    Form form2("Form 2", 1, 1);
    Form form3("Form 3", 150, 150);
    Form form4("Form 4", 2, 2);
    

    try
    {
        std::cout << Paco;
        std::cout << Alicia;
        Paco.decrementGrade();
        Alicia.incrementGrade();
        std::cout << Alicia;
        std::cout << Paco;
        
        std::cout << form1;
        std::cout << form2;
        std::cout << form3;
        std::cout << form4;
        
        Paco.signForm(form1);
        Paco.signForm(form2);
        Alicia.signForm(form3);
        Alicia.signForm(form4);
        Paco.signForm(form4);
    }
    catch (const std::exception &e)
    {
        std::cerr << BG_RED << e.what() << RST << std::endl;
    }
    
    try
	{
		Form formTest("Test Form", 151, 42);
	}
	catch(const std::exception& e)
    {
		std::cerr << BG_ORANGE << "Cannot initialize Test Form: "<< e.what() << RST << std::endl;
    }
    std::cout << form1;
    std::cout << form2;
    std::cout << form3;
    std::cout << form4;
    return (0);    
}