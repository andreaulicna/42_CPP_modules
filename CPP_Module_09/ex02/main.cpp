/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 12:38:14 by aulicna           #+#    #+#             */
/*   Updated: 2024/04/29 16:03:37 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.class.hpp"

static bool isInteger(const std::string &literal)
{
	std::istringstream	iss(literal);
	int					value;
	char				ch;

	iss >> value;
	if (iss.fail())
		return false;
	iss >> ch;
	return (iss.eof() || std::isspace(ch));
}

int	main(int argc, char **argv)
{
	int			i;

	if (argc > 1)
	{
		try
		{
			i = 1;
			while (argv[i])
			{
				 if(!isInteger(argv[i]) || std::atoi(argv[i]) < 0)
					throw(std::invalid_argument("Only positive integers are accepted on input."));
				i++;
			}
			PmergeMe pmergeme(argc, argv);
		}
		catch(const std::exception& e)
		{
			std::cerr << "Error: " << e.what() << '\n';
		}
	}
	else
	{
		std::cerr << "Error: Wrong number of program arguments.\n"
			<< "Usage: ./PmergeMe num num num..." << std::endl;
	}
	return (0);
}