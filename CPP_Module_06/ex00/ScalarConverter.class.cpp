/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.class.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 12:22:54 by aulicna           #+#    #+#             */
/*   Updated: 2024/04/20 19:12:28 by aulicna          ###   ########.fr       */
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
	std::istringstream	iss(literal);
	int					value;
	char				ch;

	iss >> value;
	if (iss.fail())
		return false;
	iss >> ch;
	return (iss.eof() || std::isspace(ch));
}

static bool isFloat(const std::string &literal)
{
	std::istringstream	iss(literal);
	float				value;
	char				ch;

	iss >> value;
	if (iss.fail())
		return false;
	iss >> ch;
	if (ch != 'f' && ch != 'F')
		return false;
	iss >> ch;
	return (iss.eof() || std::isspace(ch));
}

static bool isDouble(const std::string &literal)
{
	std::istringstream	iss(literal);
	double				value;
	char				ch;

	iss >> value;
	if (iss.fail())
		return false;
	iss >> ch;
	return (iss.eof() || std::isspace(ch));
}

static Type	detectType(const std::string &literal)
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

static void	convertFromChar(const std::string &literal, Scalars *values)
{
	values->c = static_cast<unsigned char>(literal[0]);
	values->i = static_cast<int>(values->c);
	values->f = static_cast<float>(values->c);
	values->d = static_cast<double>(values->c);
}

static void	convertFromInt(const std::string &literal, Scalars *values)
{
	values->i = std::atoi(literal.c_str());
	values->c = static_cast<unsigned char>(values->i);
	values->f = static_cast<float>(values->i);
	values->d = static_cast<double>(values->i);
}

static void	convertFromFloat(const std::string &literal, Scalars *values)
{
	values->f = std::strtof(literal.c_str(), NULL);
	values->c = static_cast<unsigned char>(values->f);
	values->i = static_cast<int>(values->f);
	values->d = static_cast<double>(values->f);
}

static void	convertFromDouble(const std::string &literal, Scalars *values)
{
	values->d = std::strtod(literal.c_str(), NULL);
	values->c = static_cast<unsigned char>(values->d);
	values->i = static_cast<int>(values->d);
	values->f = static_cast<float>(values->d);
}

static void	displayPseudoLiteral(const std::string &literal, Scalars *values)
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

static void	displayLineWithPrecision(std::string literal, Type type, Scalars *scalarValues)
{
	errno = 0;
	if (type == FLOAT)
	{
		std::strtof(literal.c_str(), NULL);
		if (errno)
			std::cout << "float: impossible" << std::endl;
		else
			std::cout << "float: " << std::fixed << std::setprecision(1)
				<< scalarValues->f << "f" << std::endl;
	}
	else if (type == DOUBLE)
	{
		std::strtod(literal.c_str(), NULL);
		if (errno)
			std::cout << "double: impossible" << std::endl;
		else
		std::cout << "double: " << std::fixed << std::setprecision(1)
			<< scalarValues->d << std::endl;
	}
}

static void	displayIntLine(std::string literal, Type type, Scalars *scalarValues)
{
	long	check; 

	check = std::strtol(literal.c_str(), NULL, 10);
	if (check < std::numeric_limits<int>::min() || check > std::numeric_limits<int>::max())
		std::cout << "int: impossible" << std::endl;
	else if (type == FLOAT && 
		(static_cast<long long>(scalarValues->f) < std::numeric_limits<int>::min()
		|| static_cast<long long>(scalarValues->f) > std::numeric_limits<int>::max()))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << scalarValues->i << std::endl;
}

static void	displayCharLine(Scalars *scalarValues)
{
	if (scalarValues->i >= 0 && scalarValues->i <= 31)
		std::cout << "char: Non displayable" << std::endl;
	else if (0 > scalarValues->i || scalarValues->i > 127)
		std::cout << "char: impossible" << std::endl;
	else
		std::cout << "char: " << scalarValues->c << std::endl;
}

static void	displayLiteral(const std::string literal, Type type, Scalars *scalarValues)
{
	if(type ==  CHAR)
	{
		std::cout << "__Detected type CHAR__" << std::endl;
		if (std::isprint(scalarValues->c))
			std::cout << "char: " << scalarValues->c << std::endl;
		else if (scalarValues->c <= 127)
			std::cout << "char: Non displayable" << std::endl;
		std::cout << "int: " << scalarValues->i << std::endl;
		displayLineWithPrecision(literal, FLOAT, scalarValues);
		displayLineWithPrecision(literal, DOUBLE, scalarValues);
		return ;
	}
	else if (type == INT)
		std::cout << "__Detected type INT__" << std::endl;
	else if (type == FLOAT)
		std::cout << "__Detected type FLOAT__" << std::endl;
	else if (type == DOUBLE)
		std::cout << "__Detected type DOUBLE__" << std::endl;
	displayCharLine(scalarValues);
	displayIntLine(literal, type, scalarValues);
	displayLineWithPrecision(literal, FLOAT, scalarValues);
	displayLineWithPrecision(literal, DOUBLE, scalarValues);
}

void	ScalarConverter::convert(std::string literal)
{
	Type	literalType;
	Scalars	scalarValues;
	void	(*convertFunctions[4])(const std::string&, Scalars*)
		= {&convertFromChar, &convertFromInt, &convertFromFloat, &convertFromDouble};

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
