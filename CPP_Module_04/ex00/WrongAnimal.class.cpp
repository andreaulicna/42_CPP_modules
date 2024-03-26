/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 10:20:03 by aulicna           #+#    #+#             */
/*   Updated: 2024/03/26 11:16:33 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.class.hpp"

// Default constructor
WrongAnimal::WrongAnimal(void)
{
	std::cout << "Default constructor of the WrongAnimal class called." << std::endl;
	this->_type = "WrongAnimal";
}

// Copy constructor
WrongAnimal::WrongAnimal(const WrongAnimal& copy)
{
	std::cout << "Copy constructor of the WrongAnimal class called." << std::endl;
	*this = copy;
}

// Copy assignment operator overload
WrongAnimal	&WrongAnimal::operator = (const WrongAnimal &src)
{
	std::cout << "Copy assignment operator of the WrongAnimal class called." << std::endl;
	if (this != &src)
	{
		this->_type = src._type;
	}
	return (*this);
}

// Destructor
WrongAnimal::~WrongAnimal(void)
{
	std::cout << "Destructor of the WrongAnimal class called." << std::endl;
}

// Getters
std::string	WrongAnimal::getType(void) const
{
	return (this->_type);
}

// Other member functions
void	WrongAnimal::makeSound(void) const
{
	std::cout << "An instance of type '" << this->_type << "' is making a sound." << std::endl;
}
