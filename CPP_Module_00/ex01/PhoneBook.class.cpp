/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 16:05:14 by aulicna           #+#    #+#             */
/*   Updated: 2024/01/09 12:48:08 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"

/* Constructor */
PhoneBook::PhoneBook(void)
{
	this->_contactsCount = 0;
	std::cout << "||======================||" << std::endl;
	std::cout << "|| My Awesome PhoneBook ||" << std::endl;
	std::cout << "||======================||" << std::endl;
	std::cout << std::endl;
	std::cout << "Available commands:\nADD, SEARCH, EXIT" << std::endl;
	std::cout << "--------------------" << std::endl;
	return ;
}

/* Destructor */
PhoneBook::~PhoneBook(void)
{
	return ;
}

void	PhoneBook::addCheat(Contact c1, Contact c2, Contact c3, Contact c4, Contact c5, Contact c6, Contact c7, Contact c8)
{
	this->_contacts[0] = c1;
	this->_contacts[1] = c2;
	this->_contacts[2] = c2;
	this->_contacts[3] = c2;
	this->_contacts[4] = c2;
	this->_contacts[5] = c2;
	//this->_contacts[6] = c2;
	//this->_contacts[7] = c2;
	this->_contactsCount = 6;
}

static int	add_handle_overwritting(void)
{
	std::string	input;

	std::cout << "Warning: The Awesome PhoneBook is full. Adding this "
		"contact will remove the oldest contact stored, contact #1. "
		"Do you want to proceed? [y/N]: ";
	std::getline(std::cin, input);
	while (input.length() != 0 && input != "Y" && input != "y"
		&& input != "n" && input != "N")
	{
		std::cout << "Do you want to proceed? [y/N]: ";
		std::getline(std::cin, input);
	}
	if (input == "Y" || input == "y")
		return (1);
	std::cout << "Abort: A new contact will not be added." << std::endl;
	return (0);
}

void	PhoneBook::add(void)
{
	Contact	tmp;

	if (this->_contactsCount >= 8)
	{
		if(!add_handle_overwritting())
			return ;
		this->_contacts[0].setContact();
		tmp = this->_contacts[0];
		for (int i = 0; i < 7; i++)
			this->_contacts[i] = this->_contacts[i + 1];
		this->_contacts[7] = tmp;
	}
	else
	{
		this->_contactsCount += 1;
		this->_contacts[this->_contactsCount - 1].setContact();
	}
	return ;
}

static void	printColumn(std::string str)
{
	int	len;

	len = str.length();
	if (len > 10)
	{
		for(int j = 0; j < 9; j++)
			std::cout << str[j];
		std::cout << ".";
	}
	else
	{
		while (len < 10)
		{
			std::cout << " ";
			len++;
		}
		std::cout << str;
	}
	std::cout << "|";
}

void	PhoneBook::displayContacts(void) const
{
	std::cout << "+============================================+" << std::endl;
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	std::cout << "+============================================+" << std::endl;

	for (int i = 0; i < this->_contactsCount; i++)
	{
		std::cout << "|";
		printColumn(std::to_string(i + 1));
		printColumn(this->_contacts[i].getFirstName());
		printColumn(this->_contacts[i].getLastName());
		printColumn(this->_contacts[i].getNickname());
		std::cout << std::endl;
	}
	std::cout << "|----------|----------|----------|----------|" << std::endl;
}

static void	printContact(Contact contact)
{
	std::cout << "First name: " << contact.getFirstName() << std::endl;
	std::cout << "Last name: " << contact.getLastName() << std::endl;
	std::cout << "Nickname: " << contact.getNickname() << std::endl;
	std::cout << "Phone number: " << contact.getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << contact.getDarkestSecret() << std::endl;
}

void	PhoneBook::search(int index) const
{
	std::string	input;

	this->displayContacts();
	std::cout << std::endl << "Enter the index of the entry to display: ";
	std::getline(std::cin, input);
	for (int i = 0; i < 8; i++)
	{
		if (input == std::to_string(i + 1))
		{
			std::cout << "Displaying entry #" << input << std::endl;
			std::cout << "-------------------" << std::endl;
			printContact(this->_contacts[i]);
			std::cout << "-------------------" << std::endl;
			return ;
		}
	}
	std::cout << "Error: Invalid index." << std::endl;
}