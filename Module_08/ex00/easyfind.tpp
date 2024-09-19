/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 14:22:23 by vkatason          #+#    #+#             */
/*   Updated: 2024/09/19 14:45:12 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

const char* NotFoundException::what() const throw()
{
    return "Element not found";
}

template <class T>
typename T::iterator easyfind(T& container, int toFind)
{
    typename T::iterator it = std::find(container.begin(), container.end(), toFind);
    if (it != container.end())
        return it;
    else
        throw NotFoundException();
}