/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 10:53:06 by vkatason          #+#    #+#             */
/*   Updated: 2024/09/30 17:59:09 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(){}

RPN::RPN(const RPN &rpn)
{
    _numberStack = rpn._numberStack;
}

RPN &RPN::operator=(const RPN &other)
{
    if (this == &other)
        return *this;
    _numberStack = other._numberStack;
    return *this;
}

RPN::~RPN(){}

void RPN::addNumber(double number)
{
	_numberStack.push(number);
}

void RPN::calculate(Operation operation)
{
	double	num1;
	double	num2;

	num1 = _numberStack.top();
	_numberStack.pop();
	num2 = _numberStack.top();
	_numberStack.pop();
	switch (operation)
	{
	case ADD:
		_numberStack.push(num2 + num1);
		break ;
	case SUBTRACT:
		_numberStack.push(num2 - num1);
		break ;
	case MULTIPLY:
		_numberStack.push(num2 * num1);
		break ;
	case DIVIDE:
		_numberStack.push(num2 / num1);
		break ;
	}
}

void RPN::returnResult()
{
	if (_numberStack.empty() || _numberStack.size() > 1)
	{
		std::cerr << RED << "Error: Coudn't calculate result. Check number of operands" << std::endl;
		std::cerr << YELLOW << "Please check the input. Usage: ./RPN <\"arguments\">" << RST << std::endl;
		return ;
	}
	std::cout << BLUE << _numberStack.top() << RST << std::endl;
}
