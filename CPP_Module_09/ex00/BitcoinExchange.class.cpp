/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.class.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 13:07:22 by aulicna           #+#    #+#             */
/*   Updated: 2024/04/26 13:01:32 aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.class.hpp"

BitcoinExchange::BitcoinExchange(void)
{
	return ;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy)
{
	this->_database = copy._database;
	this->_inputDate = copy._inputDate;
	this->_inputValue = copy._inputValue;
	this->_inputDateAsInt = copy._inputDateAsInt;
	this->_inputValueAsDouble = copy._inputValueAsDouble;
}

BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange &src)
{
	if (this != &src)
	{
		this->_database = src._database;
		this->_inputDate = src._inputDate;
		this->_inputValue = src._inputValue;
		this->_inputDateAsInt = src._inputDateAsInt;
		this->_inputValueAsDouble = src._inputValueAsDouble;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange(void)
{
	return ;
}

static std::string removeSpaces(const std::string &str)
{
	std::string noSpaces;
	
	noSpaces = str;
	noSpaces.erase(std::remove_if(noSpaces.begin(), noSpaces.end(), ::isspace), noSpaces.end());
	return (noSpaces);
}

static std::string intDateToStrDate(int dateInt)
{
	std::ostringstream	ss;

	ss << std::setw(4) << std::setfill('0') << dateInt / 10000 << "-"
	   << std::setw(2) << std::setfill('0') << (dateInt / 100) % 100 << "-"
	   << std::setw(2) << std::setfill('0') << dateInt % 100;
	return (ss.str());
}

static int	strDateToIntDate(const std::string &rawDate)
{
	std::string	newDate;

	for(size_t i = 0; i < rawDate.size(); i++)
	{
		if (rawDate[i] != '-')
			newDate += rawDate[i];
	}
	return (std::atoi(newDate.c_str()));
}

static void	validateYear(const std::string &dateToValidate, const int minDate)
{
	int					year;
	int					minYear;
	std::stringstream	ss;
	std::string			minYearStr;

	year = std::atoi(dateToValidate.substr(0, 4).c_str());
	minYear = minDate / 10000;
	if (year < minYear)
	{
		ss << minYear;
		minYearStr = ss.str();		
		throw(std::invalid_argument("The earliest year in the database is "
			+ minYearStr + ". Please don't ask for an earlier one. => "
			+ dateToValidate));
	}
}

static void	validateMonthAndDay(const std::string &dateToValidate)
{
	int					year;
	int					month;
	int					day;

	year = std::atoi(dateToValidate.substr(0, 4).c_str());
	month = std::atoi(dateToValidate.substr(5, 2).c_str());
	if (month < 1 || month > 12)
		throw(std::invalid_argument("Invalid month. => " + dateToValidate));
	day = std::atoi(dateToValidate.substr(8, 2).c_str());
	if (day < 1
			|| ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
			|| ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day > 31))
		throw(std::invalid_argument("Invalid day. => " + dateToValidate));
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
	{
		if (month == 2 && day > 29)
			throw(std::invalid_argument("Invalid day (leap year). => " + dateToValidate));
	}
	else
	{
		if (month == 2 && day > 28)
			throw(std::invalid_argument("Invalid day. => " + dateToValidate));
	}
}

static void	valideDate(const std::string &dateToValidate, const int minDate)
{
	std::string			dateFinal;

	if (dateToValidate.size() == 0)
		throw(std::invalid_argument("Date is empty. Please use YYYY-MM-DD format."));
	if (dateToValidate.find_first_not_of("0123456789-") != std::string::npos)
		throw(std::invalid_argument("Date contains invalid characters. Please use only numeric characters or '-'. => " + dateToValidate));
	if (dateToValidate[4] != '-' || dateToValidate[7] != '-' || dateToValidate.size() != 10)
		throw(std::invalid_argument("Date is wrongly formated. Please use YYYY-MM-DD format. => " + dateToValidate));
	validateYear(dateToValidate, minDate);
	validateMonthAndDay(dateToValidate);
	dateFinal = dateToValidate;
	dateFinal.erase(std::remove(dateFinal.begin(), dateFinal.end(), '-'), dateFinal.end());
	if (std::atoi(dateFinal.c_str()) < minDate)
		throw(std::invalid_argument("The earliest date in the database is "
			+ intDateToStrDate(minDate) + ". Please don't ask for an earlier one. => " + dateToValidate));	
}

static void	validateValue(const std::string &valueToValidate)
{
	std::istringstream	iss;
	double				valueAsDouble;

	if (valueToValidate.size() == 0)
		throw(std::invalid_argument("Value is empty. Please provide a float or integer between 0 and 1000."));
	if (valueToValidate.find_first_not_of("0123456789.-") != std::string::npos)
		throw(std::invalid_argument("Value contains invalid characters. Please use only numeric characters or '.'. => " + valueToValidate));
	if (valueToValidate.find_first_of(".") != valueToValidate.find_last_of(".")
		|| valueToValidate.find_first_of("-") != valueToValidate.find_last_of("-"))
		throw(std::invalid_argument("Invalid value format. Please use only numeric characters or one '.' to indicate decimal point. => " + valueToValidate));
	iss.str(valueToValidate);
	iss >> valueAsDouble;
	if (iss.fail())
		throw(std::invalid_argument("Value is not float nor integer. => " + valueToValidate));
	if (valueAsDouble < 0)
			throw(std::invalid_argument("Integer value out of range: value too low. The value must be between 0 and 1000. => " + valueToValidate));
	if (valueAsDouble > 1000)
		throw(std::invalid_argument("Integer value out of range: value too large. The value must be between 0 and 1000. => " + valueToValidate));
}

void	BitcoinExchange::_loadDatabase(const std::string &pathToDatabase)
{
	std::ifstream		databaseFile(pathToDatabase.c_str());
	std::string			line;
	std::istringstream	iss;
	std::string			rawDate;
	int					key;
	double				value;

	if(!databaseFile)
		throw(std::invalid_argument("Error: Unable to open the database file: " + pathToDatabase));
	while(std::getline(databaseFile, line))
	{
		iss.clear();
		iss.str(line);
		if (line == "date,exchange_rate")
			continue ;
		if (std::getline(iss, rawDate, ',') && (iss >> value))
			key = strDateToIntDate(rawDate);
		else
		{
			std::cerr << "Error: Cannot read line: " << line << std::endl;
			continue ;
		}
		this->_database[key] = value;
	}
	databaseFile.close();
}

void	BitcoinExchange::_processInput(const std::string &pathToInput)
{
	std::ifstream		inputFile(pathToInput.c_str());
	std::string			line;
	std::istringstream	iss;

	if (!inputFile)
		throw(std::invalid_argument("Error: Unable to open the input file: " + pathToInput));
	std::getline(inputFile, line);
	if (removeSpaces(line) != "date|value")
	{
		std::cerr << "Warning: Invalid header in the input file. Processing the first line too." << std::endl;
		// clear error flags
		inputFile.clear();
		// reset getline to the beginning
		inputFile.seekg(0, std::ios::beg);
	}
	while(std::getline(inputFile, line))
	{
		try
		{
			iss.clear();
			iss.str(line);
			if (line.empty() || line.find_first_not_of(" \t\v\n\r\f") == std::string::npos)
				throw(std::runtime_error("Line with no data to process."));
			if (removeSpaces(line) == "|" || line.find_first_of("|") == std::string::npos)
				throw(std::runtime_error("Wrongly formatted and/or incomplete line. Please use 'YYYY-MM-DD | value' format. => " + line));
			std::getline(iss, this->_inputDate, '|');
			this->_inputDate.erase(std::remove_if(this->_inputDate.begin(), this->_inputDate.end(), ::isspace), this->_inputDate.end());
			valideDate(this->_inputDate, this->_database.begin()->first);
			std::getline(iss, this->_inputValue);
			this->_inputValue.erase(std::remove_if(this->_inputValue.begin(), this->_inputValue.end(), ::isspace), this->_inputValue.end());
			validateValue(this->_inputValue);
			_printResults(this->_inputDate, this->_inputValue);
		}
		catch(const std::exception& e)
		{
			std::cerr << "Error: "<< e.what() << '\n';
		}
	}
}

void	BitcoinExchange::_printResults(const std::string &date, const std::string &value)
{
	std::map<int, double>::iterator it;
	double							result;

	this->_inputDateAsInt = strDateToIntDate(date);
	this->_inputValueAsDouble = std::strtod(value.c_str(), NULL);
	it = this->_database.lower_bound(this->_inputDateAsInt);
	if (it != this->_database.begin() && (it == this->_database.end() || it->first != this->_inputDateAsInt))
		it--;
	result = this->_inputValueAsDouble * it->second;
	std::cout << date << " => " << value << " = " << result << std::endl;
}

// For debug purposes
//void	BitcoinExchange::_printDatabase(void) const
//{
//	for(std::map<int, double>::const_iterator it = this->_database.begin(); it != this->_database.end(); ++it)
//	{
//		std::cout << it->first << ",";
//		if (it->second != static_cast<long long>(it->second))
//			std::cout << std::fixed << std::setprecision(2) << it->second << std::endl;
//		else
//			std::cout << static_cast<long long>(it->second) << std::endl;
//	}
//}

BitcoinExchange::BitcoinExchange(const std::string &pathToDatabase, const std::string &pathToInput)
{
	_loadDatabase(pathToDatabase);
	_processInput(pathToInput);
}
