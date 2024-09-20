/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 10:41:12 by vkatason          #+#    #+#             */
/*   Updated: 2024/09/20 15:08:02 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template <typename T, typename Container> MutantStack<T,
	Container>::MutantStack() : MutantStack<T, Container>::stack()
{
}

template <typename T, typename Container> MutantStack<T,
	Container>::MutantStack(const MutantStack<T,
	Container> &other) : MutantStack<T, Container>::stack(other)
{
}

template <typename T, typename Container> MutantStack<T,
	Container> &MutantStack<T, Container>::operator=(const MutantStack<T,
		Container> &rhs)
{
	if (this != &rhs)
		this->MutantStack<T, Container>::stack::operator=(rhs);
	return (*this);
}

template <typename T, typename Container> MutantStack<T,
	Container>::~MutantStack()
{
}

template <typename T, typename Container>
void MutantStack<T, Container>::printMutantStack() const
{
    typename Container::const_iterator it;
    for (it = this->c.begin(); it != this->c.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

template <typename T,
	typename Container> typename Container::iterator MutantStack<T,
	Container>::begin()
{
	return (this->c.begin());
}

template <typename T,
	typename Container> typename Container::iterator MutantStack<T,
	Container>::end()
{
	return (this->c.end());
}

template <typename T,
	typename Container> typename Container::reverse_iterator MutantStack<T,
	Container>::rbegin()
{
	return (this->c.rbegin());
}

template <typename T,
	typename Container> typename Container::reverse_iterator MutantStack<T,
	Container>::rend()
{
	return (this->c.rend());
}