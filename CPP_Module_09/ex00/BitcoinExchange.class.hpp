/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.class.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 13:07:10 by aulicna           #+#    #+#             */
/*   Updated: 2024/04/27 16:29:40 by aulicna          ###   ########.fr       */
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


 	private:
		BitcoinExchange(void);
		std::map<int, double>	_database;
		std::string				_inputDate;
		std::string				_inputValue;
		int						_inputDateAsInt;
		double					_inputValueAsDouble;

		void	_loadDatabase(const std::string &pathToDatabase);
		//void	_printDatabase(void) const;
		void	_processInput(const std::string &pathToInput);
		void	_printResults(const std::string &date, const std::string &value);
};

#endif
