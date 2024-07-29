/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 10:29:16 by vkatason          #+#    #+#             */
/*   Updated: 2024/07/29 12:38:12 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
}
Harl::~Harl()
{
}

void Harl::_debug(void)
{
	std::cout << WHITE << BG_MAGENTA << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << RST << std::endl;
}

void Harl::_info(void)
{
	std::cout << WHITE << BG_GREEN << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more! " << RST << std::endl;
}
void Harl::_warning(void)
{
	std::cout << WHITE << BG_YELLOW << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month. " << RST << std::endl;
}
void Harl::_error(void)
{
	std::cout << WHITE << BG_RED << "This is unacceptable! I want to speak to the manager. " << RST << std::endl;
}

void Harl::complaints(std::string level)
{
	std::string levels[4] = {
		"DEBUG", 
		"INFO", 
		"WARNING", 
		"ERROR"
	};
	void (Harl::*complaints[4])(void) = {
		&Harl::_debug, 
		&Harl::_info,
		&Harl::_warning, 
		&Harl::_error
	};
	for (int i = 0; i < 4; i++)
	{
		if (level == levels[i])
			(this->*complaints[i])();
	}
}
