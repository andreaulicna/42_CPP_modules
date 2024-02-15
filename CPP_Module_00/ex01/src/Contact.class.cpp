/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 14:48:34 by aulicna           #+#    #+#             */
/*   Updated: 2024/02/15 18:00:20 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Contact.class.hpp"

/**
 * @brief	Constructor.
*/
Contact::Contact(void)
{
	return ;
}

/**
 * @brief	Destructor.
*/
Contact::~Contact(void)
{
	return ;
}

/**
 * @brief	Gets a value for a member attibute of a new Contact object from
 * the standard input.
 *
 * A saved contact can't have empty fields, so the function is recursively
 * called to continue prompting the user until there is an input to return.
 * 
 * In case the variable that is being set is the phone number, there is
 * an additional check to ensure that it includes only numeric characters that
 * works the same as the check for empty input.
 *
 * @param	var_name	member attribute to get the input for
 * @return	std::string	value to set to the member attribute
*/
static std::string	setValue(std::string var_name)
{
	std::string				input;
	std::string::size_type	first;

	while (true) {
		std::cout << "Enter " << var_name << ": ";
		std::getline(std::cin, input);
		first = input.find_first_not_of(" \f\n\r\t\v");
		if (std::cin.eof())
		{
			std::cout << std::endl;
			exit(1);
		}
		if (input.length() == 0 || first == std::string::npos)
		{
			std::cout << "Error: " << (char) toupper(var_name[0]) << &var_name[1]
				<< " cannot be empty." << '\n';
			continue;
		}
		if (first != std::string::npos)
			input = input.substr(first);
		if (var_name == "phone number")
		{
			first = input.find_first_not_of("0123456789");
			if (first != std::string::npos)
			{
				std::cout << "Error: Phone number must include numeric "
					"characters only.\n";
				continue;
			}
		}
		break;
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
