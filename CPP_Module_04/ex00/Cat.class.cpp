/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.class.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 10:48:55 by aulicna           #+#    #+#             */
/*   Updated: 2024/03/26 11:36:49 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.class.hpp"

// Default constructor
Cat::Cat(void): Animal()
{
	std::cout << "Default constructor of the Cat class called." << std::endl;
	this->_type = "Cat";
}

// Copy constructor
Cat::Cat(const Cat& copy): Animal(copy)
{
	std::cout << "Copy constructor of the Cat class called." << std::endl;
	*this = copy;
}

// Copy assignment operator overload
Cat	&Cat::operator = (const Cat &src)
{
	std::cout << "Copy assignment operator of the Cat class called." << std::endl;
	if (this != &src)
	{
		this->_type = src._type;
	}
	return (*this);
}

// Destructor
Cat::~Cat(void)
{
	std::cout << "Destructor of the Cat class called." << std::endl;
}

// Other member functions
void	Cat::makeSound(void) const
{
	std::cout << "An instance of type '" << this->_type << "' is meowing." << std::endl;
}
