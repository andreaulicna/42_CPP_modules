/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.class.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 10:48:55 by aulicna           #+#    #+#             */
/*   Updated: 2024/03/26 13:21:06 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.class.hpp"

// Default constructor
Dog::Dog(void): Animal()
{
	std::cout << "Default constructor of the Dog class called." << std::endl;
	this->_type = "Dog";
}

// Copy constructor
Dog::Dog(const Dog& copy): Animal(copy)
{
	std::cout << "Copy constructor of the Dog class called." << std::endl;
	*this = copy;
}

// Copy assignment operator overload
Dog	&Dog::operator = (const Dog &src)
{
	std::cout << "Copy assignment operator of the Dog class called."
		<< std::endl;
	if (this != &src)
	{
		this->_type = src._type;
	}
	return (*this);
}

// Destructor
Dog::~Dog(void)
{
	std::cout << "Destructor of the Dog class called." << std::endl;
}

// Other member functions
void	Dog::makeSound(void) const
{
	std::cout << "An instance of type '" << this->_type << "' is barking."
		<< std::endl;
}
