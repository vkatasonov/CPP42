/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bereaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 12:22:32 by vkatason          #+#    #+#             */
/*   Updated: 2024/08/30 16:36:02 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150)
{
}

Bureaucrat::Bureaucrat(std::string const name, unsigned int grade) : _name(name)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    else
        this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy._name),
                                                 _grade(copy._grade)
{
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs)
{
    if (this != &rhs)
    {
        this->_grade = rhs._grade;
    }
    return *this;
}

Bureaucrat::~Bureaucrat()
{
}

std::string const Bureaucrat::getName() const
{
    return this->_name;
}

unsigned int Bureaucrat::getGrade() const
{
    return this->_grade;
}

void Bureaucrat::incrementGrade()
{
    if (this->_grade <= 1)
    {
        std::cout << BG_RED << "Grade of " << this->getName() << " cannot be incremented!" << RST << std::endl;
        throw Bureaucrat::GradeTooHighException();
    }
    else
    {
        this->_grade--;
        std::cout << GREEN << this->getName() << " grade had been incremented" << RST << std::endl;   
    }
}

void Bureaucrat::decrementGrade()
{
    if (this->_grade >= 150)
    {
        std::cout << BG_RED << "Grade of " << this->getName() << " cannot be decremented!" << RST << std::endl;
        throw Bureaucrat::GradeTooLowException();
    }
    else
    {
        this->_grade++;
        std::cout << YELLOW << this->getName() << " grade had been decremented" << RST << std::endl;
    }
}

void Bureaucrat::signForm(Form &form) const
{
    try
    {
        form.formSigned(*this);
        std::cout << GREEN << this->getName() << " signed " << form.getFormName() << RST << std::endl;   
    }
    catch(const std::exception& e)
    {
        std::cerr << BG_RED << this->getName() << " cannot sign " << form.getFormName()<< ": " << e.what() << RST << std::endl;
    }
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &rhs)
{
    out << BLUE << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << RST << std::endl;
    return out;
}