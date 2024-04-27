/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 17:01:10 by aulicna           #+#    #+#             */
/*   Updated: 2024/04/27 10:51:42 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.class.hpp"

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		try
		{
			RPN	rpn(argv[1]);
		}
		catch(const std::exception& e)
		{
			std::cout << "Error: " << e.what() << '\n';
		}
	}
	else
		std::cout << "Error: Wrong number of program arguments.\n"
			<< "Usage: ./RPN \"number number operation\"" << std::endl;
	return (0);
}
