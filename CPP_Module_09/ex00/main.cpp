/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 13:20:57 by aulicna           #+#    #+#             */
/*   Updated: 2024/04/27 13:05:27 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.class.hpp"

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		try
		{
			BitcoinExchange	btc("data.csv", argv[1]);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	else
		std::cerr << "Error: Wrong number of program arguments.\n"
			<< "Usage: ./btc input_file_name" << std::endl;
	return (0);
}