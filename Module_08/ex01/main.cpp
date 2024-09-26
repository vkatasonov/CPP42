/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 17:01:02 by vkatason          #+#    #+#             */
/*   Updated: 2024/09/26 15:47:23 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int	main(void)
{
	Span Span1(10);
	Span Span2(10000);

	try
	{
		//adding 10 numbers to span1 manually
        Span1.addNumber(1);
        Span1.addNumber(2);
        Span1.addNumber(3);
        Span1.addNumber(4);
        Span1.addNumber(5);
        Span1.addNumber(6);
        Span1.addNumber(7);
        Span1.addNumber(8);
        Span1.addNumber(9);
        Span1.addNumber(10);
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << e.what() << RST << std::endl;
	}
    std::cout << YELLOW << UNDER << "Span1" << RST << std::endl;
    Span1.print();
    std::cout << BLUE << "Shortest span in Span1: " << Span1.shortestSpan() << RST << std::endl;
    std::cout << BLUE << "Longest span in Span1: " << Span1.longestSpan() << RST << std::endl;

    
    std::vector<int> vec;
    for (int i = 1; i < 10000; i++)
        vec.push_back(i);
    vec.pop_back();
    //longest span in vec is 20000 - 1 = 19999 
    vec.push_back(20000);
    
    try
    {
        //adding 10000 numbers to span2 using iterators
        Span2.addNumber(vec.begin(), vec.end());
    }
    catch (const std::exception &e)
    {
        std::cerr << RED << e.what() << RST << std::endl;
    }

    std::cout << YELLOW << UNDER << "Span2" << RST << std::endl;
    Span2.print();
    std::cout << BLUE << "Shortest span in Span2: " << Span2.shortestSpan() << RST << std::endl;
    std::cout << BLUE << "Longest span in Span2: " << Span2.longestSpan() << RST << std::endl;
    
	return (0);
}
