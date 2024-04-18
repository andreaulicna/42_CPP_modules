/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:16:24 by aulicna           #+#    #+#             */
/*   Updated: 2024/04/18 14:19:04 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.class.hpp"

int	main(int argc, char **argv)
{
	if (argc == 2)
		ScalarConverter::convert(std::string(argv[1]));
	return (0);
}