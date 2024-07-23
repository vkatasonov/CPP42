/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 15:02:28 by vkatason          #+#    #+#             */
/*   Updated: 2024/07/23 17:15:00 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP
#include "Weapon.hpp"
class HumanA
{
    private:
        std::string _name;
        Weapon& _weapon;
    
    public:
        HumanA(std::string name, Weapon& weapon);
        ~HumanA();
        void attack() const;
};
#endif