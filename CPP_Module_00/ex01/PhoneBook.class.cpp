/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 16:05:14 by aulicna           #+#    #+#             */
/*   Updated: 2024/01/08 12:48:05 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"

PhoneBook::PhoneBook(void)
{
	this->_contactsCount = 0;
	std::cout << "||======================||" << std::endl;
	std::cout << "|| My Awesome PhoneBook ||" << std::endl;
	std::cout << "||======================||" << std::endl;
	std::cout << std::endl;
	std::cout << "Available commands:\nADD, SEARCH, EXIT" << std::endl;
	std::cout << "--------------------" << std::endl;
	std::cout << std::endl;
	return ;
}

PhoneBook::~PhoneBook(void)
{
	return ;
}

void	PhoneBook::add(void)
{
	int	index;
	std::string	input;

	index = this->_contactsCount;
	if (index > 7)
	{
		std::cout << "Warning: The Awesome PhoneBook is full. Adding this "
			"contact will remove the oldest contact stored, contact #1. "
			"Do you want to proceed? [Y/n]: ";
		std::getline(std::cin, input);
		while (input != "\r" && input != "Y" && input != "y"
			&& input != "n" && input != "N")
		{
			std::cout << "Do you want to proceed? [Y/n]: ";
			std::getline(std::cin, input);
		}
		this->_contactsCount -= 1;
		if (input == "\r" || input == "Y" || input == "y")
		{
			for (int i = 0; i < 7; i++)
			{
				this->_contacts[i] = this->_contacts[i + 1];
				this->_contacts[i].setIndex(i);
			}
			index = 0;
		}
		else if (input == "N" || input == "n")
		{
			std::cout << "Abort: A new contact will not be added." << std::endl;
			return ;
		}
	}
	else
		this->_contactsCount += 1;
	std::cout << "--------------------------" << std::endl;
	std::cout << "*** Adding New Contact ***" << std::endl;
	this->_contacts[index].setContact(index);
	std::cout << std::endl;
	std::cout << "Contact added as contact #" << index + 1 << "." << std::endl;
	std::cout << "--------------------------" << std::endl;
	std::cout << std::endl;
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

void	PhoneBook::displayContacts(void)
{
	std::cout << "+============================================+" << std::endl;
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	std::cout << "+============================================+" << std::endl;

	for (int i = 0; i < 8; i++)
	{
		std::cout << "|";
		printColumn(std::to_string(i));
		printColumn(this->_contacts[i].getFirstName());
		printColumn(this->_contacts[i].getLastName());
		printColumn(this->_contacts[i].getNickname());
		std::cout << std::endl;
	}
	std::cout << "|----------|----------|----------|----------|" << std::endl;
}

void	PhoneBook::search(int index)
{
	this->displayContacts();
}