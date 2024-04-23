/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.class.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 13:07:22 by aulicna           #+#    #+#             */
/*   Updated: 2024/04/23 13:48:34 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.class.hpp"

BitcoinExchange::BitcoinExchange(void)
{
	return ;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy)
{
	*this = copy;
}

BitcoinExchange	&BitcoinExchange::operator = (const BitcoinExchange &src)
{
	(void) src;
	return (*this);
}

BitcoinExchange::~BitcoinExchange(void)
{
	return ;
}

BitcoinExchange(const std::string pathToDatabase, const std::string pathToInput)
{
	(void) pathToDatabase;
	(void) pathToInput;
}
