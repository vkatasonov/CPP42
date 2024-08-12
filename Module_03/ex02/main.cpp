/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 22:34:23 by vkatason          #+#    #+#             */
/*   Updated: 2024/08/12 18:09:59 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iomanip>
#include <iostream>

void	printStatusTable(const ClapTrap &ct1, const ClapTrap &ct2,
		const ScavTrap &st1, const FragTrap &ft1)
{
	std::cout << WHITE << std::endl;
	std::cout << std::setw(20) << "" << std::setw(15) << ct1.getName() << std::setw(15) << ct2.getName() << std::setw(15) << st1.getName() << std::setw(15) << ft1.getName() << std::endl;
	std::cout << "______________________________________________________________________________________" << std::endl;
	std::cout << std::setw(20) << "Damage points"
				<< "|" << std::setw(15) << std::right << ct1.getDamage() << "|" << std::setw(15) << std::right << ct2.getDamage() << "|" << std::setw(15) << std::right << st1.getDamage() << "|" << std::setw(15) << std::right << ft1.getDamage() << "|" << std::endl;
	std::cout << "______________________________________________________________________________________" << std::endl;
	std::cout << std::setw(20) << "Health points"
				<< "|" << std::setw(15) << std::right << ct1.getHealth() << "|" << std::setw(15) << std::right << ct2.getHealth() << "|" << std::setw(15) << std::right << st1.getHealth() << "|" << std::setw(15) << std::right << ft1.getHealth() << "|" << std::endl;
	std::cout << "______________________________________________________________________________________" << std::endl;
	std::cout << std::setw(20) << "Energy points"
				<< "|" << std::setw(15) << std::right << ct1.getEnergy() << "|" << std::setw(15) << std::right << ct2.getEnergy() << "|" << std::setw(15) << std::right << st1.getEnergy() << "|" << std::setw(15) << std::right << st1.getEnergy() << "|" << std::endl;
	std::cout << "______________________________________________________________________________________" << std::endl;
	std::cout << RST << std::endl;
}

int	main(void)
{
	ClapTrap JimmyChoo("Jimmy Choo");
	ClapTrap Gaultier("Gaultier");
	ScavTrap Lagerfeld("Lagerfeld");
	FragTrap Chanel("Chanel");

	JimmyChoo.attack("Gaultier");
	Gaultier.takeDamage(0);
	printStatusTable(JimmyChoo, Gaultier, Lagerfeld, Chanel);
	Gaultier.attack("JimmyChoo");
	JimmyChoo.takeDamage(0);
	printStatusTable(JimmyChoo, Gaultier, Lagerfeld, Chanel);
	Gaultier.beRepaired(5);
	JimmyChoo.beRepaired(5);
	printStatusTable(JimmyChoo, Gaultier, Lagerfeld, Chanel);
	Gaultier.attack("Lagerfeld");
	Lagerfeld.guardGate();
	JimmyChoo.attack("Laferfeld");
	Lagerfeld.guardGate();
	printStatusTable(JimmyChoo, Gaultier, Lagerfeld, Chanel);
	Lagerfeld.attack("Gaultier");
	Gaultier.takeDamage(20);
	Lagerfeld.attack("JimmyChoo");
	JimmyChoo.takeDamage(20);
	printStatusTable(JimmyChoo, Gaultier, Lagerfeld, Chanel);
	Chanel.attack("Lagerfeld");
	Lagerfeld.takeDamage(30);
	Chanel.attack(Lagerfeld.getName());
	Lagerfeld.takeDamage(30);
	Chanel.attack(Lagerfeld.getName());
	Lagerfeld.takeDamage(30);
	Chanel.attack(Lagerfeld.getName());
	Lagerfeld.takeDamage(30);
	Chanel.highFivesGuys();
	std::cout << BG_BLACK << " 🤍 The end of designers' LOVE story 🤍 " << RST << std::endl;
	printStatusTable(JimmyChoo, Gaultier, Lagerfeld, Chanel);
	return (0);
}