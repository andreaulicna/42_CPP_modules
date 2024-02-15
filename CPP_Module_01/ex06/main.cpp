/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:39:40 by aulicna           #+#    #+#             */
/*   Updated: 2024/02/15 19:33:24 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.class.hpp"
#include <iostream>

bool	chooseComplains(Harl harl)
{
	std::string	inputLevel;
	std::cout << "___Harl's complains that you asked for (5 inputs)___\n\n";
	for (int i = 0; i < 6; i++)
	{
		std::cout << "Enter a level: ";
		std::getline(std::cin, inputLevel);
		if(std::cin.eof() == 1)
		{
			std::cerr << "\nError: Premature termination of complaining."
				<< std::endl;
			return(EXIT_FAILURE);
		}
		harl.complain(inputLevel);
		std::cout << '\n';
	}
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	Harl		harl;
	std::string	levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	std::string	limit;

	if (argc == 2)
		harl.complain(argv[1]);
	else
		harl.complain("INVALID");
	return (EXIT_SUCCESS);
}
