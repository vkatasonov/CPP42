/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 12:04:15 by vkatason          #+#    #+#             */
/*   Updated: 2024/09/05 16:58:04 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(const std::string &name) : _name(name),
                                        _target(""),
                                        _signed(false),
                                        _signGrade(1),
                                        _execGrade(1)
{
}

AForm::AForm(const std::string &name,
             const std::string &target) : _name(name),
                                          _target(target),
                                          _signed(false),
                                          _signGrade(1),
                                          _execGrade(1)
{
}

AForm::AForm(const std::string &name, unsigned int signGrade,
             unsigned int execGrade) : _name(name),
                                       _target(""),
                                       _signed(false),
                                       _signGrade(signGrade),
                                       _execGrade(execGrade)
{
    if (signGrade < 1 || execGrade < 1)
        throw AForm::GradeTooHighException();
    else if (signGrade > 150 || execGrade > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(const std::string &name, const std::string &target,
             unsigned int signGrade, unsigned int execGrade) : _name(name),
                                                              _target(target),
                                                              _signed(false),
                                                              _signGrade(signGrade),
                                                              _execGrade(execGrade)
{
    if (signGrade < 1 || execGrade < 1)
        throw AForm::GradeTooHighException();
    else if (signGrade > 150 || execGrade > 150)
        throw AForm::GradeTooLowException();
}
        
AForm::AForm(const AForm &copy) : _name(copy._name),
                                  _target(copy._target),
                                  _signed(copy._signed),
                                  _signGrade(copy._signGrade), 
                                  _execGrade(copy._execGrade)
{
}

AForm &AForm::operator=(const AForm &rhs)
{
    (void)rhs;
    return (*this);
}

AForm::~AForm()
{
}

// Getter for AForm parameters

std::string const AForm::getFormName() const
{
    return (this->_name);
}

std::string const AForm::getTarget() const
{
    return (this->_target);
}

bool AForm::getSignedStatus() const
{
    return (this->_signed);
}

unsigned int AForm::getSignGrade() const
{
    return (this->_signGrade);
}

unsigned int AForm::getExecGrade() const
{
    return (this->_execGrade);
}

void AForm::formSigned(const Bureaucrat &bureaucrat)
{
    if (!this->_signed)
    {
        if (bureaucrat.getGrade() <= this->_signGrade)
            this->_signed = true;
        else
            throw AForm::GradeTooLowException();
    }
    else
        throw AForm::FormIsSigned();
}

void AForm::formExec(const Bureaucrat &bureaucrat) const
{
    if (!this->_signed)
        throw AForm::FormIsNotSigned();
    if(bureaucrat.getGrade() > this->_execGrade)
        throw AForm::GradeTooLowException();
}

// Operator overload for cout (<<) for AForm
std::ostream &operator<<(std::ostream &out, const AForm &rhs)
{
    const int width = 45;

    out << std::string(width, '-') << std::endl;
    out << "| " << YELLOW << std::left << std::setw(20) << "Form:" << RST << std::setw(21) << rhs.getFormName() << " |" << std::endl;
    out << "| " << YELLOW << std::left << std::setw(20) << "Target:" << RST << std::setw(21) << rhs.getTarget() << " |" << std::endl;
    out << "| " << YELLOW << std::left << std::setw(20) << "Signed status:" << RST << std::setw(21) << std::boolalpha << rhs.getSignedStatus() << " |" << std::endl;
    out << "| " << YELLOW << std::left << std::setw(20) << "Sign grade:" << RST << std::setw(21) << rhs.getSignGrade() << " |" << std::endl;
    out << "| " << YELLOW << std::left << std::setw(20) << "Execution grade:" << RST << std::setw(21) << rhs.getExecGrade() << " |" << std::endl;
    out << std::string(width, '-') << std::endl;
    return (out);
}
