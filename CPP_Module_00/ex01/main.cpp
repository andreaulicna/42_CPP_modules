/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 15:35:16 by aulicna           #+#    #+#             */
/*   Updated: 2024/01/09 12:43:25 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.class.hpp"
#include "PhoneBook.class.hpp"

int	main(void)
{
	std::string	command;
	PhoneBook	phonebook;
	Contact c1;
	Contact	c2;
	Contact	c3;
	Contact	c4;
	Contact	c5;
	Contact	c6;
	Contact	c7;
	Contact	c8;

	c1.setContactCheatFirst();
	c2.setContactCheat();
	c3.setContactCheat();
	c4.setContactCheat();
	c5.setContactCheat();
	c6.setContactCheat();
//	c7.setContactCheat();
//	c8.setContactCheat();
	phonebook.addCheat(c1, c2, c3, c4, c5, c6, c7, c8);

	std::cout << "Enter a command: ";
	std::getline(std::cin, command);
	while (command != "EXIT")
	{
		if (command.length() == 0)
		{
			std::cout << "Enter a command: ";
			std::getline(std::cin, command);
			continue ;
		}
		else if (command == "ADD")
			phonebook.add();
		else if (command == "SEARCH")
			phonebook.search(0);
		else
			std::cout << "Error: Not a valid command. "
				"Enter ADD, SEARCH or EXIT." << std::endl;
		std::cout << "Enter a command: ";
		std::getline(std::cin, command);
	}
	return (0);
}