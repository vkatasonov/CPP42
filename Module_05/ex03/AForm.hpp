/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 12:04:05 by vkatason          #+#    #+#             */
/*   Updated: 2024/09/06 14:31:46 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Bureaucrat.hpp"
#include <iomanip>
#include <iostream>
#include <string>

class	Bureaucrat;

class AForm
{
  private:
	std::string const _name;
	std::string const _target;
	bool _signed;
	unsigned int const _signGrade;
	unsigned int const _execGrade;

	AForm() : _name(""), 
              _target(""), 
              _signed(false), 
              _signGrade(1),
              _execGrade(1)
    {};

  public:

  //Constructors & Destructors
  AForm(const std::string &name);
  AForm(const std::string &name, 
        const std::string &target);
  AForm(const std::string &name,
        const unsigned int signGrade,
        const unsigned int execGrade);
  AForm(const std::string &name, 
        const std::string &target,
        const unsigned int signGrade,
        const unsigned int execGrade);
  AForm(const AForm &copy);
  ~AForm();
  
  //Igualation operator overload
  AForm &operator=(const AForm &rhs);

  //Getters for AForm

  std::string const getFormName() const;
  std::string const getTarget() const;
  bool getSignedStatus() const;
  unsigned int getSignGrade() const;
  unsigned int getExecGrade() const;
  
  /**
   * @brief   Function changes the form status
   *          to signed if the bureaucrat’s
   *          grade is high enough (>= to required)
   */
    void formSigned(const Bureaucrat &bureaucrat);
    
  /**
   * @brief   Function executes the form 
   *          if the bureaucrat’s grade is 
   *          high enough and if the form is 
   *          signed 
   */
    void formExec(const Bureaucrat& bureaucrat) const;

  /**
   * @brief   Pure virtual function that will be
   *          implemented in derived classes 
   *          to execute the form 
   */
    virtual void execute(const Bureaucrat &bureaucrat) const = 0;

    class GradeTooHighException : public std::exception
    {
        const char *what() const throw()
        {
            return ("Grade is too high!");
        }
    };

    class GradeTooLowException : public std::exception
    {
        const char *what() const throw()
        {
            return ("Grade is too low!");
        }
    };

    class FormIsSigned : public std::exception
    {
        const char *what() const throw()
        {
            return ("Form is already signed!");
        }
    };

    class FormIsNotSigned : public std::exception
    {
        const char *what() const throw()
        {
            return ("Form is not signed!");
        }
    };
};

// Operator overload for cout (<<) for Form
std::ostream& operator<<(std::ostream &out, const AForm &rhs);