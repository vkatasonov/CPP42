/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 15:02:44 by vkatason          #+#    #+#             */
/*   Updated: 2024/07/23 17:01:08 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP
#include "Weapon.hpp"

class HumanB
{
private:
    std::string _name;
    Weapon *_weapon;

public:
    HumanB(std::string name);
    ~HumanB();
    
    void setWeapon(Weapon &weapon);    
    void attack() const;
};

#endif