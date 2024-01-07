/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 16:05:14 by aulicna           #+#    #+#             */
/*   Updated: 2024/01/07 17:48:45 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"

PhoneBook::PhoneBook(void)
{
	this->_contactsCount = 0;
	std::cout << "====================" << std::endl;
	std::cout << "My Awesome PhoneBook" << std::endl;
	std::cout << "====================" << std::endl;
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

	index = this->_contactsCount;

	std::cout << "--------------------------" << std::endl;
	std::cout << "*** Adding New Contact ***" << std::endl;
	this->_contacts[index].setContact(index);
	//std::cout << this->_contacts[index].getFirstName() << std::endl;
	//std::cout << this->_contacts[index].getLastName() << std::endl;
	//std::cout << this->_contacts[index].getNickname() << std::endl;
	//std::cout << this->_contacts[index].getPhoneNumber() << std::endl;
	//std::cout << this->_contacts[index].getDarkestSecret() << std::endl;
	std::cout << std::endl;
	std::cout << "Contact added as contact number " << index << "." << std::endl;
	std::cout << "--------------------------" << std::endl;
	std::cout << std::endl;
	this->_contactsCount += 1;
	return ;
}

//int main( void ) {
//    
//    char    buff[512];
//
//    std::cout << "Hello world !" << std::endl;
//
//    std::cout << "Input a word: ";
//    std::cin >> buff;
//    std::cout << "You entered :[" << buff << "]" << std::endl;
//
//    return 0;
//}

//void	PhoneBook::search(int index)
//{
//	return (this->_contacts[index]);
//}