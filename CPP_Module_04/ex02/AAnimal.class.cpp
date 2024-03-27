/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 10:20:03 by aulicna           #+#    #+#             */
/*   Updated: 2024/03/27 18:46:09 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.class.hpp"

// Default constructor
AAnimal::AAnimal(void)
{
	std::cout << "Default constructor of the AAnimal class called." << std::endl;
	this->_type = "AAnimal";
}

// Copy constructor
AAnimal::AAnimal(const AAnimal& copy)
{
	std::cout << "Copy constructor of the AAnimal class called." << std::endl;
	*this = copy;
}

// Copy assignment operator overload
AAnimal	&AAnimal::operator = (const AAnimal &src)
{
	std::cout << "Copy assignment operator of the AAnimal class called."
		<< std::endl;
	if (this != &src)
		this->_type = src._type;
	return (*this);
}

// Destructor
AAnimal::~AAnimal(void)
{
	std::cout << "Destructor of the AAnimal class called." << std::endl;
}

// Getters
const std::string	AAnimal::getType(void) const
{
	return (this->_type);
}
