/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 15:35:16 by aulicna           #+#    #+#             */
/*   Updated: 2024/02/15 20:02:20 by aulicna          ###   ########.fr       */
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
	std::string				command;
	PhoneBook				phonebook;
	std::string::size_type	first;

	command = enterCommand();
	first = command.find_first_not_of(" \f\n\r\t\v");
	while (command != "EXIT")
	{
		if (command.length() == 0)
		{
			command = enterCommand();
			continue ;
		}
		if (first != std::string::npos)
			command = command.substr(first);
		if (command == "ADD")
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
