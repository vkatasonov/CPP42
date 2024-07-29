/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 10:27:42 by vkatason          #+#    #+#             */
/*   Updated: 2024/07/29 12:40:27 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv)
{
    Harl harl;

    if (argc == 2)
    {
        std::string levels[4] = {
            "DEBUG",
            "INFO",
            "WARNING",
            "ERROR"};
        int i = 0;
        while (i < 4 && levels[i] != argv[1])
            i++;
        switch (i)
        {
        case 0:
            std::cout << BG_BLUE << "[ " << levels[0] << " ]" << RST << std::endl;
            harl.complaints(levels[0]);
            std::cout << std::endl;
            break;
        case 1:
            std::cout << BG_GREEN << "[ " << levels[1] << " ]" << RST << std::endl;
            harl.complaints(levels[1]);
            std::cout << std::endl;
            break;
        case 2:
            std::cout << BG_YELLOW << "[ " << levels[2] << " ]" << RST << std::endl;
            harl.complaints(levels[2]);
            std::cout << std::endl;
            break;
        case 3:
            std::cout << BG_RED << "[ " << levels[3] << " ]" << RST << std::endl;
            harl.complaints(levels[3]);
            std::cout << std::endl;
            break;
        default:
            std::cout << BG_BLUE << "[ Other crazy stuff. Let him keep complaining ]" RST << std::endl;
        }
    }
    else if (argc != 2)
    {
        std::cout << RED << "Error: Incorrect number of arguments" << RST << std::endl;
        std::cout << YELLOW << "Usage :./Harl [DEBUG | INFO | WARNING | ERROR]" << std::endl;
    }
    return (0);
}
