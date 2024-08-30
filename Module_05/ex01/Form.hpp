/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 12:04:05 by vkatason          #+#    #+#             */
/*   Updated: 2024/08/30 16:39:53 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Bureaucrat.hpp"
#include <iostream>
#include <string>
#include <iomanip>

class Bureaucrat;

class Form
{
private:
    std::string const _name;
    bool _signed;
    unsigned int const _signGrade;
    unsigned int const _execGrade;

    Form() : _name(""),
             _signed(false),
             _signGrade(1),
             _execGrade(1) {};

public:
    Form(const std::string &name);
    Form(const std::string &name,
         unsigned int singGrade,
         unsigned int execGrade);
    Form(const Form &copy);
    Form &operator=(const Form &rhs);
    ~Form();

    // Getters for Form parameters

    std::string const getFormName() const;
    bool getSignedStatus() const;
    unsigned int getSignGrade() const;
    unsigned int getExecGrade() const;

    class GradeTooHighException : public std::exception
    {
        const char *what() const throw()
        {
            return ("Grade is too high to sign!");
        }
    };

    class GradeTooLowException : public std::exception
    {
        const char *what() const throw()
        {
            return ("Grade is too low to sign!");
        }
    };

    class FormIsSigned : public std::exception
    {
        const char *what() const throw()
        {
            return ("Form is already signed!");
        }
    };

    /**
     * @brief   Function changes the form status
     *          to signed if the bureaucrat’s
     *          grade is high enough (>= to required)
     */
    void formSigned(const Bureaucrat &bureaucrat);
};

// Operator overload for cout (<<) for Form
std::ostream &operator<<(std::ostream &out, const Form &rhs);
