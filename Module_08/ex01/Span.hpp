/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:10:27 by vkatason          #+#    #+#             */
/*   Updated: 2024/09/19 16:53:08 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>
#include <limits>

class Span
{
    private:
        unsigned int _size;
        std::vector<int> _vec;
    
    public:
    // Constructors & Destructor
    Span();
    Span(const unsigned int &N);
    Span(const Span &span);
    ~Span();

    // Operator Overloads
    Span &operator=(const Span &span);
    
    // Member Functions
    void addNumber(const int &num);
    void addNumber(const std::vector<int>::iterator &begin, const std::vector<int>::iterator &end);
    unsigned int shortestSpan() const;
    unsigned int longestSpan() const;

    // Exceptions
    class SpanFullException : public std::exception
    {
        public:
            const char *what() const throw()
            {
                return "Span is full";
            }
    };

    class SpanEmptyException : public std::exception
    {
        public:
            const char *what() const throw()
            {
                return "Span is too short";
            }
    };
};