/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 10:20:03 by aulicna           #+#    #+#             */
/*   Updated: 2024/03/26 13:20:42 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.class.hpp"

// Default constructor
Animal::Animal(void)
{
	std::cout << "Default constructor of the Animal class called." << std::endl;
	this->_type = "Animal";
}

// Copy constructor
Animal::Animal(const Animal& copy)
{
	std::cout << "Copy constructor of the Animal class called." << std::endl;
	*this = copy;
}

// Copy assignment operator overload
Animal	&Animal::operator = (const Animal &src)
{
	std::cout << "Copy assignment operator of the Animal class called."
		<< std::endl;
	if (this != &src)
	{
		this->_type = src._type;
	}
	return (*this);
}

// Destructor
Animal::~Animal(void)
{
	std::cout << "Destructor of the Animal class called." << std::endl;
}

// Getters
std::string	Animal::getType(void) const
{
	return (this->_type);
}

// Other member functions
void	Animal::makeSound(void) const
{
	std::cout << "An instance of type '" << this->_type
		<< "' is making a sound." << std::endl;
}
