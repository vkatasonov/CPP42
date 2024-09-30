/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 10:53:16 by vkatason          #+#    #+#             */
/*   Updated: 2024/09/30 11:48:50 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int argc, char **argv)
{
		RPN rpn;

	if (argc == 2)
	{
		const std::string input = argv[1];
		for (std::string::const_iterator it = input.begin(); it != input.end(); it++)
		{
			if (std::isdigit(*it))
			{
				rpn.addNumber(*it - '0');
				continue ;
			}
			switch (*it)
			{
			case '+':
				rpn.calculate(ADD);
				break ;
			case '-':
				rpn.calculate(SUBTRACT);
				break ;
			case '*':
				rpn.calculate(MULTIPLY);
				break ;
			case '/':
				rpn.calculate(DIVIDE);
				break ;
			case ' ':
				break ;
			default:
				std::cout << RED << "Error: Invalid character '" << *it << "' in input" << RST << std::endl;
				return (1);
			}
		}
		rpn.returnResult();
	}
	else
	{
		std::cout << RED << "Error: Invalid number of arguments." << RST << std::endl;
        std::cout << YELLOW << "Usage: ./program \"<expression>\"" << RST << std::endl;
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
