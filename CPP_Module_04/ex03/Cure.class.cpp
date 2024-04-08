/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.class.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 19:06:03 by aulicna           #+#    #+#             */
/*   Updated: 2024/03/27 20:53:31 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.class.hpp"

// Default constructor
Cure::Cure(void): AMateria()
{
	std::cout << "Default constructor of the Cure class called." << std::endl;
	this->_type = "cure";
}

// Copy constructor
Cure::Cure(const Cure& copy): AMateria(copy)
{
	std::cout << "Copy constructor of the Cure class called." << std::endl;
	*this = copy;
}

// Copy assignment operator overload
Cure	&Cure::operator = (const Cure &src)
{
	std::cout << "Copy assignment operator of the Cure class called."
		<< std::endl;
	if (this != &src)
	{
		this->_type = src._type;
		this->_isEquipped = false;
	}
	return (*this);
}

// Destructor
Cure::~Cure(void)
{
	std::cout << "Destructor of the Cure class called." << std::endl;
}

// Other member functions
AMateria*	Cure::clone(void) const
{
	return (new Cure());	
}

void Cure::use(ICharacter& target)
{
	std::cout << "Cure: * heals " << target.getName() << "'s wounds *"
		<< std::endl;
}