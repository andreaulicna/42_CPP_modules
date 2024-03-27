/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.class.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 19:06:03 by aulicna           #+#    #+#             */
/*   Updated: 2024/03/27 20:53:31 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.class.hpp"

// Default constructor
Ice::Ice(void): AMateria()
{
	std::cout << "Default constructor of the Ice class called." << std::endl;
	this->_type = "ice";
}

// Copy constructor
Ice::Ice(const Ice& copy): AMateria(copy)
{
	std::cout << "Copy constructor of the Ice class called." << std::endl;
	*this = copy;
}

// Copy assignment operator overload
Ice	&Ice::operator = (const Ice &src)
{
	std::cout << "Copy assignment operator of the Ice class called."
		<< std::endl;
	if (this != &src)
	{
		this->_type = src._type;
		this->_isEquipped = false;
	}
	return (*this);
}

// Destructor
Ice::~Ice(void)
{
	std::cout << "Destructor of the Ice class called." << std::endl;
}

// Other member functions
AMateria*	Ice::clone(void) const
{
	return (new Ice());	
}

void Ice::use(ICharacter& target)
{
	std::cout << "Ice: * shoots an ice bolt at " << target.getName() << "*" << std::endl;
}