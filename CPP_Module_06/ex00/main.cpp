/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:16:24 by aulicna           #+#    #+#             */
/*   Updated: 2024/04/20 19:13:34 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.class.hpp"

int	main(int argc, char **argv)
{
	if (argc == 2)
		ScalarConverter::convert(std::string(argv[1]));
	else
		std::cout << "Error: Wrong number of arguments. "
			<< "Please provide a literal." << std::endl;
	return (0);
}