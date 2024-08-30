/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 12:04:15 by vkatason          #+#    #+#             */
/*   Updated: 2024/08/30 16:43:53 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(const std::string &name) : _name(name),
                                      _signed(false),
                                      _signGrade(1),
                                      _execGrade(1)
{
}

Form::Form(const std::string &name,
           unsigned int signGrade,
           unsigned int execGrade) : _name(name),
                                     _signed(false),
                                     _signGrade(signGrade),
                                     _execGrade(execGrade)
{
    if (signGrade < 1 || execGrade < 1)
        throw Form::GradeTooHighException();
    else if (signGrade > 150 || execGrade > 150)
        throw Form::GradeTooLowException();
}

Form::Form(const Form &copy) : _name(copy._name),
                               _signed(copy._signed),
                               _signGrade(copy._signGrade),
                               _execGrade(copy._execGrade)
{
}

Form &Form::operator=(const Form &rhs)
{
    (void)rhs;
    return (*this);
}

Form::~Form()
{
}

// Getter for Form parameters

std::string const Form::getFormName() const
{
    return this->_name;
}

bool Form::getSignedStatus() const
{
    return this->_signed;
}

unsigned int Form::getSignGrade() const
{
    return this->_signGrade;
}

unsigned int Form::getExecGrade() const
{
    return this->_execGrade;
}

void Form::formSigned(const Bureaucrat &bureaucrat)
{
    if (!this->_signed)
    {
        if (bureaucrat.getGrade() <= this->_signGrade)
            this->_signed = true;        
        else
            throw Form::GradeTooLowException();
    }
    else 
        throw Form::FormIsSigned();
}


// Operator overload for cout (<<) for Form

std::ostream& operator<<(std::ostream& out, const Form& rhs) 
{
    const int width = 40;

    out << std::string(width, '-') << std::endl;
    out << "| " << YELLOW << std::left << std::setw(18) << "Form:" << RST << std::setw(18) << rhs.getFormName() << " |" << std::endl;
    out << "| " << YELLOW << std::left << std::setw(18) << "Signed status:" << RST << std::setw(18) << std::boolalpha << rhs.getSignedStatus() << " |" << std::endl;
    out << "| " << YELLOW << std::left << std::setw(18) << "Sign grade:" << RST << std::setw(18) << rhs.getSignGrade() << " |" << std::endl;
    out << "| " << YELLOW << std::left << std::setw(18) << "Execution grade:" << RST << std::setw(18) << rhs.getExecGrade() << " |" << std::endl;
    out << std::string(width, '-') << std::endl;

    return out;
}

