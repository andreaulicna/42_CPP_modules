/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 14:48:34 by aulicna           #+#    #+#             */
/*   Updated: 2024/01/08 11:52:08 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.class.hpp"

Contact::Contact(void)
{
	return ;
}

Contact::~Contact(void)
{
	return ;
}

// Setters
void	Contact::setIndex(int index)
{
	this->_index = index;
}

void	Contact::setContact(int index)
{
	this->_index = index;
	std::cout << "Enter first name: ";
	std::getline(std::cin, this->_firstName);
	while (this->_firstName.length() == 0 || std::iswspace(this->_firstName[0]))
	{
		std::cout << "Error: First name cannot be empty." << std::endl;
		std::cout << "Enter first name: ";
		std::getline(std::cin, this->_firstName);
	}
	std::cout << "Enter last name: ";
	std::getline(std::cin, this->_lastName);
	while (this->_lastName.length() == 0 || std::iswspace(this->_lastName[0]))
	{
		std::cout << "Error: Last name cannot be empty." << std::endl;
		std::cout << "Enter last name: ";
		std::getline(std::cin, this->_lastName);
	}
	std::cout << "Enter nickname: ";
	std::getline(std::cin, this->_nickname);
	while (this->_nickname.length() == 0 || std::iswspace(this->_nickname[0]))
	{
		std::cout << "Error: Nickname cannot be empty." << std::endl;
		std::cout << "Enter nickname: ";
		std::getline(std::cin, this->_nickname);
	}
	std::cout << "Enter phone number: ";
	std::getline(std::cin, this->_phoneNumber);
	while (this->_phoneNumber.length() == 0
		|| std::iswspace(this->_phoneNumber[0]))
	{
		std::cout << "Error: Phone number cannot be empty." << std::endl;
		std::cout << "Enter phone number: ";
		std::getline(std::cin, this->_phoneNumber);
	}
	std::cout << "Enter darkest secrete: ";
	std::getline(std::cin, this->_darkestSecret);
	while (this->_darkestSecret.length() == 0
		|| std::iswspace(this->_darkestSecret[0]))
	{
		std::cout << "Error: Darkest secrete cannot be empty." << std::endl;
		std::cout << "Enter darkest secrete: ";
		std::getline(std::cin, this->_darkestSecret);
	}
}

// Getter
std::string	Contact::getFirstName(void) const
{
	return (this->_firstName);
}

std::string	Contact::getLastName(void) const
{
	return (this->_lastName);
}

std::string	Contact::getNickname(void) const
{
	return (this->_nickname);
}

std::string	Contact::getPhoneNumber(void) const
{
	return (this->_phoneNumber);
}

std::string	Contact::getDarkestSecret(void) const
{
	return (this->_darkestSecret);
}
