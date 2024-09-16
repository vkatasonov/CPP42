/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 16:55:45 by vkatason          #+#    #+#             */
/*   Updated: 2024/09/16 19:04:43 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <iostream>
#include <string>

template <typename T>
class Array
{
private:
    T *_arr;
    unsigned int _size;

public:
    // Default constructor
    Array() : _arr(new T[0]), _size(0) {};
    
    // Parametrized constructor
    Array(unsigned int n) : _arr(new T[n]), _size(n) {};

    // Copy constructor
    Array(const Array &other) : _arr(new T[other._size]), _size(other._size)
    {
        for (unsigned int i = 0; i < other._size; i++)
            this->_arr[i] = other._arr[i];
    };

    // Destructor
    ~Array()
    {
        delete[] this->_arr;
    };

    // Assignment operator overload
    Array &operator=(const Array &rhs)
    {
        if (this != &rhs)
        {
            delete[] this->_arr;
            this->_arr = new T[rhs._size];
            this->_size = rhs._size;
            for (unsigned int i = 0; i < rhs._size; i++)
                this->_arr[i] = rhs._arr[i];
        }
        return (*this);
    };

    T &operator[](unsigned int index)
    {
        if (index >= this->_size)
            throw OutOfBounds();
        return (this->_arr[index]);
    };

    // Getter
    unsigned int getSize() const
    {
        return (this->_size);
    };

    // Exception class
    class OutOfBounds : public std::exception
    {
    public:
        const char *what() const throw()
        {
            return "Error: Element is out of bounds";
        }
    };
};

/*
** ASCII colors escape sequences for printf
*/
#define RST "\033[0m"					            /* Reset to default color */
#define BU "\033[1;4;0m"				            /* Bold and underlined text*/
#define BOLD "\033[1m"						            /* Bold text default color */
#define U "\033[4m"						            /* Underlined text default color */
#define RED "\033[1;31m"				            /* Bold Red*/
#define GREEN "\033[1;32m"				            /* Bold Green */
#define YELLOW "\033[1;33m"				            /* Bold Yellow */
#define BLUE "\033[1;34m"				            /* Bold Blue */
#define MAGENTA "\033[1;35m"			            /* Bold Magenta */
#define CYAN "\033[1;36m"				            /* Bold Cyan */
#define WHITE "\033[1;37m"				            /* Bold White */
#define ORANGE "\033[1m\033[38;2;255;165;0m"	    /* Orange */
#define VIOLET "\033[1m\033[38;2;238;130;238m"	    /* Violet */
#define BG_BLACK "\033[40m"				            /* Background Black */
#define BG_GREEN "\033[42m"				            /* Background Green */
#define BG_YELLOW "\033[43m"			            /* Background Yellow */
#define BG_RED "\033[41m"				            /* Background Red */
#define BG_BLUE "\033[44m"				            /* Background Blue */
#define BG_MAGENTA "\033[45m"			            /* Background Magenta */
#define BG_CYAN "\033[46m"				            /* Background Cyan */
#define BG_WHITE "\033[47m"				            /* Background White */
#define BG_ORANGE "\033[48;2;255;165;0m"            /* Background Orange */
#define BG_VIOLET "\033[48;2;238;130;238m"          /* Background Violet */
#define BG_RESET "\033[49m"				            /* Background Reset */