/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 15:35:16 by aulicna           #+#    #+#             */
/*   Updated: 2024/01/08 11:40:58 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.class.hpp"
#include "PhoneBook.class.hpp"

int	main(void)
{
	std::string	command;
	PhoneBook	phonebook;

	phonebook.add();
	phonebook.add();
	phonebook.add();
	while (command != "EXIT")
	{
		std::cout << "Enter a command: ";
		std::getline(std::cin, command);
		if (command.length() == 0)
			continue ;
		else if (command == "ADD")
			phonebook.add();
		else if (command == "SEARCH")
			phonebook.search(0);
		else
			std::cout << "Error: Not a valid command. "
				"Enter ADD, SEARCH or EXIT." << std::endl;
	}
	return (0);
}