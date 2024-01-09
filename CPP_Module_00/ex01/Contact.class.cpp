/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 14:48:34 by aulicna           #+#    #+#             */
/*   Updated: 2024/01/09 12:53:15 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.class.hpp"

/* Constructor */
Contact::Contact(void)
{
	return ;
}

/* Destructor */
Contact::~Contact(void)
{
	return ;
}

void	Contact::setContactCheatFirst(void)
{
	this->_firstName = "1";
	this->_lastName = "2";
	this->_nickname = "3";
	this->_phoneNumber = "4";
	this->_darkestSecret = "5";
}

void	Contact::setContactCheat(void)
{
	this->_firstName = "jou";
	this->_lastName = "hej";
	this->_nickname = "haha";
	this->_phoneNumber = "ahsfks;djf";
	this->_darkestSecret = "tbtltt";
}

// Setters
void	Contact::setContact()
{
	std::cout << "--------------------------" << std::endl;
	std::cout << "*** Adding New Contact ***" << std::endl;
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
	std::cout << std::endl;
	std::cout << "Contact successfully added." << std::endl;
	std::cout << "--------------------------" << std::endl;
	std::cout << std::endl;
}

// Getters
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
