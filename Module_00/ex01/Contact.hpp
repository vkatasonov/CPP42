/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:31:43 by vkatason          #+#    #+#             */
/*   Updated: 2024/06/25 12:59:14 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>

class Contact
{
	private:
		std::string _firstName;
		std::string _lastName;
		std::string _phoneNumber;
		std::string _nickName;
		std::string _darkestSecret;
	
	public:
		// Empty constructor
		Contact()
		{};
		
		// Empty destructor
		~Contact()
		{};
		
		//Getters functions
		std::string getFirstName() const;
		std::string getLastName() const;
		std::string getPhoneNumber() const;
		std::string getNickName() const;
		std::string getDarkestSecret() const;
		
		//Setters functions
		void setFirstName(std::string firstName);
		void setLastName(std::string lastName);
		void setPhoneNumber(std::string phoneNumber);
		void setNickName(std::string nickName);
		void setDarkestSecret(std::string darkestSecret);
};

#endif