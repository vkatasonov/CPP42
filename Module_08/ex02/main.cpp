/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 10:35:19 by vkatason          #+#    #+#             */
/*   Updated: 2024/09/20 15:45:47 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stack>
#include "MutantStack.hpp"

int main()
{
    MutantStack<int> mstack;
    std::cout << BG_BLUE << WHITE << "MutantStack test" << RST << std::endl;
    std::cout << GREEN << "Pushing elements: " << RST << "5 17" << std::endl;
    mstack.push(5);
    mstack.push(17);
    std::cout << YELLOW << "Current stack state: " << RST;
    mstack.printMutantStack();
    
    std::cout << BLUE << "Top element: " << RST << mstack.top() << std::endl;
    
    std::cout << RED << "Popping element" << RST << std::endl;
    mstack.pop();
    std::cout << YELLOW << "Stack size after pop: " << RST << mstack.size() << std::endl;
    std::cout << YELLOW << "Current stack state: " << RST;
    mstack.printMutantStack();
    std::cout << GREEN << "Pushing elements: " << RST << "3 5 737 0" << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    std::cout << YELLOW << "Current stack state: " << RST;
    mstack.printMutantStack();

    // Iterators move check 
    std::cout << BG_BLUE << WHITE << "Moving iterator -> and <-" << RST << std::endl;
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    std::cout << YELLOW << "Current stack state: " << RST;
    mstack.printMutantStack();

    std::cout << YELLOW << UNDER << "Iterating through stack:" << RST << std::endl;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    
    // Stack copy check
    
    MutantStack<int> s(mstack);
    std::cout << BG_BLUE << WHITE << "Stack copy" << RST << std::endl;
    std::cout << YELLOW << "Current stack state: " << RST;
    s.printMutantStack();

    // Assignment operator check
    MutantStack<int> s2;
    s2 = mstack;
    std::cout << BG_BLUE << WHITE << "Assignment operator" << RST << std::endl;
    std::cout << YELLOW << "Current stack state: " << RST;
    s2.printMutantStack();

    // Reverse iterator check
    
    std::cout << BG_BLUE << WHITE << "Reverse iterator" << RST << std::endl;
    MutantStack<int>::reverse_iterator revit = mstack.rbegin();
    MutantStack<int>::reverse_iterator revite = mstack.rend();

    std::cout << YELLOW << UNDER << "Iterating through stack:" << RST << std::endl;
    while (revit != revite)
    {
        std::cout << *revit << std::endl;
        ++revit;
    }
    
    return 0;
}