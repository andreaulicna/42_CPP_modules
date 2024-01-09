/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 16:05:14 by aulicna           #+#    #+#             */
/*   Updated: 2024/01/09 22:11:15 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/PhoneBook.class.hpp"

/* Constructor */
PhoneBook::PhoneBook(void)
{
	this->_contactsCount = 0;
	std::cout << "||======================||\n";
	std::cout << "|| My Awesome PhoneBook ||\n";
	std::cout << "||======================||\n\n";
	std::cout << "Available commands:\nADD, SEARCH, EXIT\n";
	std::cout << "--------------------" << std::endl;
	return ;
}

/* Destructor */
PhoneBook::~PhoneBook(void)
{
	return ;
}

// Getters
Contact	PhoneBook::getContact(int index) const
{
	return (this->_contacts[index]);
}

int	PhoneBook::getCountactsCount(void) const
{
	return (this->_contactsCount);
}

// Other methods
static int	addHandleOverwritting(void)
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
		if(!addHandleOverwritting())
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

static void	printColumnOfPhonebook(std::string str)
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

static int	displayPhonebook(PhoneBook *phonebook)
{
	if (phonebook->getCountactsCount() == 0)
	{
		std::cout << "My Awesome PhoneBook: Nothing to display as no contacts "
			<< "have been saved yet." << std::endl;
			return (0);
	}
	std::cout << "+============================================+\n";
	std::cout << "|     Index|First Name| Last Name|  Nickname|\n";
	std::cout << "+============================================+\n";

	for (int i = 0; i < phonebook->getCountactsCount(); i++)
	{
		std::cout << "|";
		printColumnOfPhonebook(std::to_string(i + 1));
		printColumnOfPhonebook(phonebook->getContact(i).getFirstName());
		printColumnOfPhonebook(phonebook->getContact(i).getLastName());
		printColumnOfPhonebook(phonebook->getContact(i).getNickname());
	}
	std::cout << "\n|----------|----------|----------|----------|" << std::endl;
	return (1);
}

static void	printFoundEntry(Contact contact)
{
	std::cout << "First name: " << contact.getFirstName() << '\n';
	std::cout << "Last name: " << contact.getLastName() << '\n';
	std::cout << "Nickname: " << contact.getNickname() << '\n';
	std::cout << "Phone number: " << contact.getPhoneNumber() << '\n';
	std::cout << "Darkest Secret: " << contact.getDarkestSecret() << '\n';
}

void	PhoneBook::search(void) const
{
	std::string	input;

	if (!displayPhonebook((PhoneBook *) this))
		return ;
	std::cout << "\nEnter the index of the entry to display: ";
	std::getline(std::cin, input);
	if (input > std::to_string(this->_contactsCount) && input < "9")
	{
		std::cout << "Nothing to display for entry #" << input
			<< " as the phonebook has only " << this->_contactsCount
			<< " contact(s) so far." << std::endl;
		return ;
	}
	for (int i = 0; i < 8; i++)
	{
		if (input == std::to_string(i + 1))
		{
			std::cout << "Displaying entry #" << input << '\n';
			std::cout << "-------------------\n";
			printFoundEntry(this->_contacts[i]);
			std::cout << "-------------------" << std::endl;
			return ;
		}
	}
	std::cout << "Error: Invalid index." << std::endl;
}
