/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.class.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 18:43:11 by aulicna           #+#    #+#             */
/*   Updated: 2024/03/27 22:31:47 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.class.hpp"

// Default constructor
AMateria::AMateria(void): _type("materia"), _isEquipped(false)
{
	std::cout << "Default constructor of the AMateria class called." << std::endl;
}

// Constructor overloads
AMateria::AMateria(std::string const & type): _type(type), _isEquipped(false)
{
	std::cout << "Constructor overload of the AMateria class called." << std::endl;
}

// Copy constructor
AMateria::AMateria(const AMateria& copy)
{
	std::cout << "Copy constructor of the AMateria class called." << std::endl;
	this->_type = copy._type;
}

// Copy assignment operator overload
AMateria	&AMateria::operator = (const AMateria &src)
{
	std::cout << "Copy assignment operator of the AMateria class called."
		<< std::endl;
	if (this != &src)
	{
		this->_type = src._type;
		this->_isEquipped = src._isEquipped;
	}
	return (*this);
}

// Destructor
AMateria::~AMateria(void)
{
	std::cout << "Destructor of the AMateria class called." << std::endl;
}

// Getters
std::string const &AMateria::getType() const
{
	return (this->_type);
}

bool	AMateria::getIsEquipped(void) const
{
	return (this->_isEquipped);
}

// Setters
void	AMateria::setIsEquipped(bool state)
{
	this->_isEquipped = state;
}


void AMateria::use(ICharacter& target)
{
	std::cout << "AMateria: * being used on " << target.getName() << "*" << std::endl;
}
