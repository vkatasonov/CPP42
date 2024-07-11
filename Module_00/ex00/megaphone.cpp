/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 10:10:22 by vkatason          #+#    #+#             */
/*   Updated: 2024/07/11 12:48:56 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream> // for std::cout

/**
 * @brief 		The program takes a string as an argument and prints it in uppercase.
 * 
 * @param argc 	The number of arguments passed to the program.
 * @param argv 	The arguments passed to the program.
 * 
 * @return int 	Returns 0 if the program runs successfully.
 * @var i 		An integer to loop through the arguments.
 * @var j 		An integer to loop through the characters of the argument.
 */
int	main(int argc, char **argv)
{
	int i;
	int j;

	i = 0;
	if (argc > 1)
	{
		while (argv[++i]) // skip the first argument and loop through the rest
		{
			j = 0;
			while (argv[i][j]) // loop through each character of the argument
			{
				std::cout << (char)toupper(argv[i][j]);
				j++;
			}
		}
		std::cout << std::endl;
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	return (0);
}