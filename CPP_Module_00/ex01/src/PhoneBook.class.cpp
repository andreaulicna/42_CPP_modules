/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 16:05:14 by aulicna           #+#    #+#             */
/*   Updated: 2024/01/13 11:33:24 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/PhoneBook.class.hpp"

/**
 * @brief	Constructor.
 * 
 * Prints a welcome message and available commands.
*/
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

/**
 * @brief	Destructor.
*/
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

// Other methods and helper functions
/**
 * @brief	Asks the user whether the oldest contact should be overwritten when
 * the phonebook is full.
 *
 * The default is N to avoid accidently deleted a contact
 *
 * @return 	1 if the user chooses to proceed, 0 if the user decides to abort
 */
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

/**
 * @brief	Saves a new contact in the phonebook.
 *
 * If the phonebook is full, it invokes addHandleOverwriting to ask the user
 * whether the oldest contact (#1) should be overwritten. If so, the contact
 * is saved on that position and then the whole phonebook is shifted, so that
 * the newly added contact is now the youngest, i.e #8. Otherwise, an abort
 * message is printed and no new contact added.
 *
 * If the phonebook is not full, the function adds a new contact to it
 * by prompting the user to input information one field at a time.
 */
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

/**
 * @brief Prints a formatted column of the phonebook.
 * 
 * It ensures a maximum width of 10 characters and right-alignment. When
 * the string is longer than 10 characters, it is truncated and the last
 * displayable character is replaced by a dot.
 *
 * @param	str	the string to be printed
 */
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

/**
 * @brief	Displays the contents of the phonebook in a formatted table.
 *
 * If there are no contacts, it prints a message indicating that no contacts
 * have been saved.
 *
 * @param	phonebook	PhoneBook object to display
 * @return	0 if no contacts are available, 1 otherwise
 */
static int	displayPhonebook(PhoneBook *phonebook)
{
	if (phonebook->getCountactsCount() == 0)
	{
		std::cout << "My Awesome PhoneBook: Nothing to display as no contacts "
			<< "have been saved yet." << std::endl;
			return (0);
	}
	std::cout << "+===========================================+\n";
	std::cout << "|     Index|First Name| Last Name|  Nickname|\n";
	std::cout << "+===========================================+\n";

	for (int i = 0; i < phonebook->getCountactsCount(); i++)
	{
		std::cout << "|";
		printColumnOfPhonebook(std::to_string(i + 1));
		printColumnOfPhonebook(phonebook->getContact(i).getFirstName());
		printColumnOfPhonebook(phonebook->getContact(i).getLastName());
		printColumnOfPhonebook(phonebook->getContact(i).getNickname());
		std::cout << '\n';
	}
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	return (1);
}

/**
 * @brief	Prints the details of a found contact entry after the SEARCH has
 * been run.
 *
 * @param	contact	contact object to be displayed
 */
static void	printFoundEntry(Contact contact)
{
	std::cout << "First name: " << contact.getFirstName() << '\n';
	std::cout << "Last name: " << contact.getLastName() << '\n';
	std::cout << "Nickname: " << contact.getNickname() << '\n';
	std::cout << "Phone number: " << contact.getPhoneNumber() << '\n';
	std::cout << "Darkest Secret: " << contact.getDarkestSecret() << '\n';
}

/**
 * @brief	Searches for a contact in the phonebook and displays its details.
 *
 * Prompts the user to enter the index of the entry to display. If the index
 * is invalid or exceeds the available contacts, a corresponding error message
 * is displayed - different for when the index is actually invalid (i.e. not
 * a number or index > 8) and when there are not yet enough contacts saved
 * in the phonebok (index < 8)
 */
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
