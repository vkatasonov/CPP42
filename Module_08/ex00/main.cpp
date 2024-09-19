/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 15:17:21 by vkatason          #+#    #+#             */
/*   Updated: 2024/09/19 15:08:00 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
    std::vector<int> vec;
    std::list<int> lst;
    int random;
    int position;

    std::cout << YELLOW << "Input number of element in vector: " << RST;
    int v;
    std::cin >> v;
    
    std::cout << YELLOW << "Input number of elements in list: " << RST;
    int l;
    std::cin >> l;

    std::cout << YELLOW << "Vector: " << RST;   
    for (int i = 0; i < v; i++)
    {
        random = rand() % 100;
        vec.push_back(random);
        std::cout << random << " ";
    }

    std::cout << std::endl << YELLOW << "List: " << RST;
    for (int i = 0; i < l; i++)
    {
        random = rand() % 100;
        lst.push_back(random);
        std::cout << random << " ";
    }

    std::cout << std::endl << YELLOW << "Enter a number to find in vector: " << RST;
    int toFind;
    std::cin >> toFind;
    
    try
    {
        std::vector<int>::iterator it_vector = easyfind(vec, toFind);
        std::cout << GREEN << "Element found: " << *it_vector << RST;
        position = std::distance(vec.begin(), it_vector) + 1;
        std::cout << GREEN << " Position in vector: " << position << RST << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << RED << e.what() << " in vector" << RST << std::endl;
    }

    std::cout << YELLOW << "Enter a number to find in list: " << RST;
    std::cin >> toFind;
    try
    {
       std::list<int>::iterator it_list = easyfind(lst, toFind);
       std::cout << GREEN << "Element found :" << *it_list << RST;
       position = std::distance(lst.begin(), it_list) + 1;
       std::cout << GREEN << " Position in list: " << position << RST << std::endl;      
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << e.what() << " in list" << RST << '\n';
    }
    return 0;
}