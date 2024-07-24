/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 10:27:42 by vkatason          #+#    #+#             */
/*   Updated: 2024/07/24 13:58:39 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
    Harl harl;

    harl.complaints("DEBUG");
    harl.complaints("INFO");
    harl.complaints("WARNING");
    harl.complaints("ERROR");
    return (0);
}