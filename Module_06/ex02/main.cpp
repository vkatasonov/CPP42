/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 16:41:43 by vkatason          #+#    #+#             */
/*   Updated: 2024/09/13 18:05:25 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate()
{
	std::cout << BLUE << "Instance generated: " << RST;
	switch (rand() % 3)
	{
	case 0:
		std::cout << YELLOW << "A" << RST;
		return new A();
	case 1:
		std::cout << YELLOW << "B" << RST;
		return new B();
	case 2:
		std::cout << YELLOW << "C" << RST;
		return new C();
	default:
		return NULL;
	}
}

void identify(Base* p)
{
	std::cout << BLUE << "Pointer points to: " << RST;
	if (dynamic_cast<A*>(p))
		std::cout << YELLOW << "A type object" << RST << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << YELLOW << "B type object" << RST << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << YELLOW << "C type object" << RST << std::endl;
	else
		std::cerr << "bad cast" << std::endl;

}

void identify(Base& p)
{
	try
	{
		std::cout << BLUE << "Pointer reference to: " << RST;
		if (dynamic_cast<A*>(&p))
			std::cout << YELLOW << "A type object" << RST<< std::endl;
		else if (dynamic_cast<B*>(&p))
			std::cout << YELLOW << "B type object" <<  RST<< std::endl;
		else if (dynamic_cast<C*>(&p))
			std::cout << YELLOW << "C type object" <<  RST<< std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << RED << e.what() << RST << std::endl;
	}
}

int main()
{
	srand(time(NULL));
	Base* ptr = generate();
	std::cout << YELLOW <<" pointer" << RST << std::endl;
	Base* tmp = generate();
	Base& ref = *tmp;
	std::cout << YELLOW << " reference" << RST << std::endl;

	identify(ptr);
	identify(ref);

	delete ptr;
	delete tmp;
}