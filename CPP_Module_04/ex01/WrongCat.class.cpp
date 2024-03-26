/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.class.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 10:48:55 by aulicna           #+#    #+#             */
/*   Updated: 2024/03/26 11:17:34 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.class.hpp"

// Default constructor
WrongCat::WrongCat(void): WrongAnimal()
{
	std::cout << "Default constructor of the WrongCat class called."
		<< std::endl;
	this->_type = "WrongCat";
}

// Copy constructor
WrongCat::WrongCat(const WrongCat& copy): WrongAnimal(copy)
{
	std::cout << "Copy constructor of the WrongCat class called." << std::endl;
	*this = copy;
}

// Copy assignment operator overload
WrongCat	&WrongCat::operator = (const WrongCat &src)
{
	std::cout << "Copy assignment operator of the WrongCat class called."
		<< std::endl;
	if (this != &src)
	{
		this->_type = src._type;
	}
	return (*this);
}

// Destructor
WrongCat::~WrongCat(void)
{
	std::cout << "Destructor of the WrongCat class called." << std::endl;
}

// Other member functions
void	WrongCat::makeSound(void) const
{
	std::cout << "An instance of type '" << this->_type << "' is meowing."
		<< std::endl;
}
