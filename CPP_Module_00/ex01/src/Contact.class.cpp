/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 14:48:34 by aulicna           #+#    #+#             */
/*   Updated: 2024/01/09 14:54:05 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Contact.class.hpp"

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

static std::string	setValue(std::string var_name)
{
	std::string	input;

	std::cout << "Enter " << var_name << ": ";
	std::getline(std::cin, input);
	while (input.length() == 0 || std::iswspace(input[0]))
	{
		std::cout << "Error: " << (char) toupper(var_name[0]) << &var_name[1]
			<< " cannot be empty." << std::endl;
		std::cout << "Enter " << var_name << ": ";
		std::getline(std::cin, input);
	}
	return (input);
}

// Setters
void	Contact::setContact()
{
	std::cout << "--------------------------\n";
	std::cout << "*** Adding New Contact ***\n";
	this->_firstName = setValue("first name");
	this->_lastName = setValue("last name");
	this->_nickname = setValue("nickname");
	this->_phoneNumber = setValue("phone number");
	this->_darkestSecret = setValue("darkest secret");
	std::cout << "\nContact successfully added.\n";
	std::cout << "--------------------------" << std::endl;
}

void	Contact::setFirstName(std::string value)
{
	this->_firstName = value;
}

void	Contact::setLastName(std::string value)
{
	this->_lastName = value;
}

void	Contact::setNickname(std::string value)
{
	this->_nickname = value;
}

void	Contact::setPhoneNumber(std::string value)
{
	this->_phoneNumber = value;
}

void	Contact::setDarkestSecret(std::string value)
{
	this->_darkestSecret = value;
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
