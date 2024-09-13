/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 11:51:29 by vkatason          #+#    #+#             */
/*   Updated: 2024/09/13 16:00:22 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

uintptr_t Serializer::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data *Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}

//empty constructor
Serializer::Serializer()
{
}

//empty destructor
Serializer::~Serializer()
{
}

//empty copy constructor
Serializer::Serializer(const Serializer &)
{
}

//empty assignment operator overload
Serializer &Serializer::operator=(const Serializer &rhs)
{
    (void)rhs;
    return (*this);
}