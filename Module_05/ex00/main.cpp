/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 15:35:51 by vkatason          #+#    #+#             */
/*   Updated: 2024/08/29 17:10:34 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    Bureaucrat Paco("Paco", 1);
    Bureaucrat Alicia("Alicia", 150);

    try
    {
        std::cout << Paco;
        std::cout << Alicia;
        Paco.decrementGrade();
        Alicia.incrementGrade();
        std::cout << Alicia;
        std::cout << Paco;
        Paco.incrementGrade();
        Alicia.decrementGrade();
        std::cout << Alicia;
        std::cout << Paco;
        Alicia.decrementGrade();
    }
    catch (const std::exception &e)
    {
        std::cerr << BG_RED << e.what() << RST << std::endl;
    }

    return (0);
}