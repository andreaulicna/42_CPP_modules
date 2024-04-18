/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.class.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 12:22:54 by aulicna           #+#    #+#             */
/*   Updated: 2024/04/18 22:24:51 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.class.hpp"

ScalarConverter::ScalarConverter(void)
{
	return ;
}

ScalarConverter::ScalarConverter(const ScalarConverter& copy)
{
	*this = copy;
}

ScalarConverter	&ScalarConverter::operator = (const ScalarConverter &src)
{
	(void) src;
	return (*this);
}

ScalarConverter::~ScalarConverter(void)
{
	return ;
}

static bool isChar(const std::string &literal)
{
	return (literal.length() == 1);
}

static bool isInteger(const std::string &literal)
{
	std::istringstream	iss;
	int					value;

	iss.str(literal);
	iss >> value;
	return (iss.eof() && !iss.fail());
}

static bool isFloat(const std::string &literal)
{
	std::istringstream iss(literal);
	float value;
	char ch;

	iss >> value;
	if (iss.fail())
		return false;
	iss >> ch;
	return (ch == 'f' || ch == 'F');
}

static bool isDouble(const std::string &literal)
{
	std::istringstream	iss;
	double				value;

	iss.str(literal);
	iss >> value;
	return (iss.eof() && !iss.fail());
}

Type	detectType(const std::string &literal)
{
	if (literal == "-inff" || literal == "+inff" || literal == "nanf"
		|| literal == "-inf" || literal == "+inf" || literal == "nan")
		return (PSEUDO);
	else if (isInteger(literal))
		return (INT);
	else if (isFloat(literal))
		return (FLOAT);
	else if (isDouble(literal))
		return (DOUBLE);
	else if (isChar(literal))
		return (CHAR);
	return (WRONG);
}

void	convertFromChar(const std::string &literal, Scalars *values)
{
	values->c = static_cast<char>(literal[0]);
	values->i = static_cast<int>(values->c);
	values->f = static_cast<float>(values->c);
	values->d = static_cast<double>(values->c);
}

void	convertFromInt(const std::string &literal, Scalars *values)
{
	values->i = std::atoi(literal.c_str());
	values->c = static_cast<char>(values->i);
	values->f = static_cast<float>(values->i);
	values->d = static_cast<double>(values->i);
}

void	convertFromFloat(const std::string &literal, Scalars *values)
{
	values->f = std::strtof(literal.c_str(), NULL);
	values->c = static_cast<char>(values->f);
	values->i = static_cast<int>(values->f);
	values->d = static_cast<double>(values->f);
}

void	convertFromDouble(const std::string &literal, Scalars *values)
{
	values->d = std::strtod(literal.c_str(), NULL);
	values->c = static_cast<char>(values->d);
	values->i = static_cast<int>(values->d);
	values->f = static_cast<float>(values->d);
}

void	displayPseudoLiteral(const std::string &literal, Scalars *values)
{
	if (literal == "-inf" || literal == "-inff")
	{
		values->f = static_cast<float>(std::numeric_limits<float>::infinity() * -1.f);
		values->d = static_cast<double>(std::numeric_limits<double>::infinity() * -1.);
	}
	else if (literal == "+inf" || literal == "+inff")
	{
		values->f = static_cast<float>(std::numeric_limits<float>::infinity());
		values->d = static_cast<double>(std::numeric_limits<double>::infinity());
	}
	else if (literal == "nan" || literal == "nanf")
	{
		values->f = static_cast<float>(std::numeric_limits<float>::quiet_NaN());
		values->d = static_cast<double>(std::numeric_limits<double>::quiet_NaN());
	}
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << values->f << "f" << std::endl;
	std::cout << "double: " << values->d << std::endl;
}

void	displayLiteral(const std::string literal, Type type, Scalars *scalarValues)
{
	(void) literal;
	(void) type;
	(void) scalarValues;
	std::cout << "Hej" << std::endl;
}

void	ScalarConverter::convert(std::string literal)
{
	Type	literalType;
	Scalars	scalarValues;
	void	(*convertFunctions[4])(const std::string&, Scalars*) = {&convertFromChar, &convertFromInt, &convertFromFloat, &convertFromDouble};

	literalType = detectType(literal);
	if (literalType == WRONG)
		std::cerr << "Error: Invalid input. "
			<< "Only char, int, float and double are accepted." << std::endl;
	else if (literalType == PSEUDO)
		displayPseudoLiteral(literal, &scalarValues);
	else
	{
		for (int i = 0; i < 4; i++)
		{
			if (literalType == static_cast<Type>(i))
			{
				convertFunctions[i](literal, &scalarValues);
				break;
			}
		}
		displayLiteral(literal, literalType, &scalarValues);
	}
}
