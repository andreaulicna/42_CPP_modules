/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 15:35:16 by aulicna           #+#    #+#             */
/*   Updated: 2024/02/15 17:18:54 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Contact.class.hpp"
#include "../incl/PhoneBook.class.hpp"

static std::string	enterCommand()
{
	std::string	command;

	std::cout << "Enter a command: ";
	std::getline(std::cin, command);
	if (std::cin.eof() == 1)
	{
		std::cout << std::endl;
		command = "EXIT";
	}
	return (command);
}

int	main(void)
{
	std::string	command;
	PhoneBook	phonebook;

	command = enterCommand();
	while (command != "EXIT")
	{
		if (command.length() == 0)
		{
			command = enterCommand();
			continue ;
		}
		else if (command == "ADD")
			phonebook.add();
		else if (command == "SEARCH")
			phonebook.search();
		else
			std::cout << "Error: Not a valid command. "
				<< "Enter ADD, SEARCH or EXIT." << std::endl;
		command = enterCommand();
	}
	return (0);
}
