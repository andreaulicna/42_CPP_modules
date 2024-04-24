/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.class.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 13:07:10 by aulicna           #+#    #+#             */
/*   Updated: 2024/04/24 18:30:31 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_CLASS_HPP
# define BITCOINEXCHANGE_CLASS_HPP

# include <iostream>
# include <map>
# include <fstream>
# include <sstream>
# include <cstdlib>
# include <iomanip>
# include <cmath>
# include <algorithm>
# include <ctime>

class BitcoinExchange
{
	public:
		BitcoinExchange(const std::string &pathToDatabase, const std::string &pathToInput);
		BitcoinExchange(const BitcoinExchange& copy);
		BitcoinExchange	&operator=(const BitcoinExchange &src);
		~BitcoinExchange(void);

		void	loadDatabase(const std::string &pathToDatabase);
		void	printDatabase(void) const;
		void	processInput(const std::string &pathToInput);

 	private:
		BitcoinExchange(void);
		std::map<int, double>	_database;

		void	loadDatabase(std::ifstream &database);


};

#endif
