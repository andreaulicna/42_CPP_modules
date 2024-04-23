/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.class.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 13:07:10 by aulicna           #+#    #+#             */
/*   Updated: 2024/04/23 13:45:47 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_CLASS_HPP
# define BITCOINEXCHANGE_CLASS_HPP

# include <iostream>
# include <map>

class BitcoinExchange
{
	public:
		BitcoinExchange(const std::string pathToDatabase, const std::string pathToInput);
		BitcoinExchange(const BitcoinExchange& copy);
		BitcoinExchange	&operator=(const BitcoinExchange &src);
		~BitcoinExchange(void);

	private:
		BitcoinExchange(void);
		std::map<int, double>	_database;

		void	loadDatabase(std::ifstream &database);


};

#endif
