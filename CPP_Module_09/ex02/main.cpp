/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 12:38:14 by aulicna           #+#    #+#             */
/*   Updated: 2024/04/27 13:58:55 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.class.hpp"

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		try
		{
			PmergeMe pmergeme(argc, argv);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	else
	{
		std::cerr << "Error: Wrong number of program arguments.\n"
			<< "Usage: ./PmergeMe num num num..." << std::endl;
	}
	
	return (0);
}