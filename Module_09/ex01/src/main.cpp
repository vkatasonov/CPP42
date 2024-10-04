/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 10:53:16 by vkatason          #+#    #+#             */
/*   Updated: 2024/10/04 16:35:18 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv)
{
    RPN rpn;

    if (argc == 2)
    {
        const std::string input = argv[1];
        std::istringstream iss(input);
        std::string token;

        while (iss >> token)
        {
            if (std::isdigit(token[0]) || (token[0] == '-' && token.size() > 1 && std::isdigit(token[1])))
            {
                std::stringstream ss(token);
                int number;
                ss >> number;
				if (!(number < 0) && !(number >= 10))
                	rpn.addNumber(number);
				else
				{
					std::cerr << RED << "Error: Invalid number: " << number << std::endl;
					exit(1);
				}	
                continue;
            }
            if (token.size() == 1)
            {
                switch (token[0])
                {
                case '+':
                    rpn.calculate(ADD);
                    break;
                case '-':
                    rpn.calculate(SUBTRACT);
                    break;
                case '*':
                    rpn.calculate(MULTIPLY);
                    break;
                case '/':
                    rpn.calculate(DIVIDE);
                    break;
                default:
                    std::cerr << "Error: Invalid characters in input" << std::endl;
                    exit(1);
                }
            }
            else
            {
                std::cout << "Error: Invalid token: " << token << std::endl;
                return 1;
            }
        }
        rpn.returnResult();
    }
    else
    {
        std::cout << RED << "Error: Invalid number of arguments." << RST << std::endl;
        std::cout << YELLOW << "Usage: ./program \"<expression>\"" << RST << std::endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
