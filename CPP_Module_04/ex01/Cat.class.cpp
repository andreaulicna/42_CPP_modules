/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.class.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 10:48:55 by aulicna           #+#    #+#             */
/*   Updated: 2024/03/27 11:51:38 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.class.hpp"

// Default constructor
Cat::Cat(void): Animal()
{
	std::cout << "Default constructor of the Cat class called." << std::endl;
	this->_type = "Cat";
	this->_brain = new Brain();
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
	std::cout << "Copy assignment operator of the Cat class called."
		<< std::endl;
	if (this != &src)
	{
		this->_type = src._type;
		if (src._brain)
			this->_brain = new Brain(*src._brain);
		else
			this->_brain = NULL;
	}
	return (*this);
}

// Destructor
Cat::~Cat(void)
{
	delete this->_brain;
	std::cout << "Destructor of the Cat class called." << std::endl;
}

// Getters
void	Cat::getBrainContent(void) const
{
	std::cout << "___Cat's Brain___" << "\n";
	for (int i = 0; i < 100 && this->_brain->getIdea(i).length() > 0; i++)
		std::cout << "Idea " << i << ": '" << this->_brain->getIdea(i) << "' saved at " << this->_brain->getIdeaAddress(i) << std::endl;
}

// Setters
void	Cat::setIdea(std::string idea, int i)
{
	this->_brain->setIdea(idea, i);
}

// Other member functions
void	Cat::makeSound(void) const
{
	std::cout << "An instance of type '" << this->_type << "' is meowing."
		<< std::endl;
}

void	Cat::brainDump(void) const
{
	std::cout << "Cat's brain: " << this->_brain << std::endl;
}
