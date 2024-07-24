/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 10:51:00 by vkatason          #+#    #+#             */
/*   Updated: 2024/07/24 12:59:25 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <string>
/*
** ASCII colors escape sequences for printf
** Usage:
**      ft_printf(RED "Red bold text" RST);
**		ft_printf(B "Bold text goes here" RST);
*/
#define RST "\033[0m"         /* Reset to default color */
#define BU "\033[1;4;0m"      /* Bold and underlined text*/
#define B "\033[1m"           /* Bold text default color */
#define U "\033[4m"           /* Underlined text default color */
#define RED "\033[1;31m"      /* Bold Red*/
#define GREEN "\033[1;32m"    /* Bold Green */
#define YELLOW "\033[1;33m"   /* Bold Yellow */
#define BLUE "\033[1;34m"     /* Bold Blue */
#define MAGENTA "\033[1;35m"  /* Bold Magenta */
#define CYAN "\033[1;36m"     /* Bold Cyan */
#define WHITE "\033[1;37m"    /* Bold White */
#define BG_BLACK "\033[40m"   /* Background Black */
#define BG_GREEN "\033[42m"   /* Background Green */
#define BG_YELLOW "\033[43m"  /* Background Yellow */
#define BG_RED "\033[41m"     /* Background Red */
#define BG_BLUE "\033[44m"    /* Background Blue */
#define BG_MAGENTA "\033[45m" /* Background Magenta */
#define BG_CYAN "\033[46m"    /* Background Cyan */
#define BG_WHITE "\033[47m"   /* Background White */

void replaceString(char **argv)
{
    std::string const filename = argv[1];
    std::string const s1 = argv[2];
    std::string const s2 = argv[3];
    
    std::ifstream file((filename).c_str());
    if (file.good())
    {
        if (file.peek() == std::ifstream::traits_type::eof())       // Check is the first read character is EOF
            std::cerr << WHITE << BG_RED " Error: file is empty " RST << std::endl;
        else 
        {
            std::ofstream newfile((filename + ".replace").c_str());
            while (file.good() && newfile.good())
            {
                std::string line;                                   // Serves to store the line read from the file
                std::size_t pos;                                    // Stores the position of the string to replace
                std::getline(file, line);                           // Read lines from the file
                pos = line.find(s1, 0);                             // Find the first occurrence of the string to replace
                while (pos != std::string::npos)                    // Until search is successful
                {
                    line.erase(pos, s1.length());                   // Erase the string to replace
                    line.insert(pos, s2);                           // Insert the string to replace with       
                    pos = line.find(s1, pos);                       // Move the pointer to the next position of the string to replace
                }
                newfile << line;                                    // Write the modified line to the new file
                if (file.eof())                                     
                    break;
                newfile << std::endl;                               // Add a newline to the new file     
            }
            file.close();                                           // Close the file
            newfile.close();                                        // Close the new file
        }
    }
    else
        std::cerr << WHITE << BG_RED " Error: Couldn't open the file " RST << std::endl;
}

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << WHITE << BG_RED " Error: wrong number of arguments " RST << std::endl;
		std::cout << WHITE << BG_YELLOW << 
                " Usage: ./replace <filename> <string to replace> <string to replace with> " << RST << std::endl;
        return (1);
	}
	else
		replaceString(argv);

	return (0);
}