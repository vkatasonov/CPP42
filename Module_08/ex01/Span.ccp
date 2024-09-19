/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.ccp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:10:48 by vkatason          #+#    #+#             */
/*   Updated: 2024/09/19 16:58:36 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _size(0)
{
}

Span::Span(const unsigned int &N) : _size(N)
{
}

Span::Span(const Span &other) : _size(other._size), _vec(other._vec)
{
}

Span &Span::operator=(const Span &rhs)
{
	if (this != &rhs)
	{
		this->_size = rhs._size;
		this->_vec = rhs._vec;
	}
	return (*this);
}

Span::~Span()
{
}

void Span::addNumber(const int &num)
{
	if (this->_vec.size() >= this->_size)
		throw SpanFullException();
	this->_vec.push_back(num);
}

void Span::addNumber(const std::vector<int>::iterator &begin,
	const std::vector<int>::iterator &end)
{
	int	distance;

	distance = std::distance(begin, end);
	if (this->_vec.size() + distance > this->_size)
	{
		this->_vec.insert(this->_vec.end(), begin, begin + (this->_size
				- this->_vec.size()));
		throw SpanFullException();
	}
	else
		this->_vec.insert(this->_vec.end(), begin, end);
}

unsigned int Span::shortestSpan() const
{
	if (this->_vec.size() <= 1)
		throw SpanEmptyException();

	// Create a copy of the vector and sort it
	std::vector<int> sorted_v(this->_vec);
	std::sort(sorted_v.begin(), sorted_v.end());

	// Initialize the minimum span to a large value
	unsigned int min_span = std::numeric_limits<unsigned int>::max();

	// Iterate through the sorted vector and find the minimum difference
	for (size_t i = 1; i < sorted_v.size(); ++i)
	{
		unsigned int span = sorted_v[i] - sorted_v[i - 1];
		if (span < min_span)
		{
			min_span = span;
		}
	}
	return (min_span);
}

unsigned int Span::longestSpan() const
{
	if (this->_vec.size() <= 1)
		throw SpanEmptyException();

	// Find the maximum and minimum elements in the vector
	int max_elem = *std::max_element(this->_vec.begin(), this->_vec.end());
	int min_elem = *std::min_element(this->_vec.begin(), this->_vec.end());

	// Calculate and return the longest span
	return (max_elem - min_elem);
}


