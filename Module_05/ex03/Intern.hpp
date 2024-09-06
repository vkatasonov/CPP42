/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 12:46:46 by vkatason          #+#    #+#             */
/*   Updated: 2024/09/06 14:31:14 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"

class Intern
{ 
  public:
    Intern();
    Intern(const Intern &copy);
    Intern &operator=(const Intern &rhs);
    ~Intern();

    class InvalidFormException : public std::exception
    {
      public:
        const char *what() const throw()
        {
            return ("Invalid form type");
        };
    };
    
    AForm *makeForm(const std::string &formName, const std::string &target);
};
