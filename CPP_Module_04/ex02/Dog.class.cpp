/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.class.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 10:48:55 by aulicna           #+#    #+#             */
/*   Updated: 2024/04/08 19:33:33 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.class.hpp"

// Default constructor
Dog::Dog(void): AAnimal()
{
	std::cout << "Default constructor of the Dog class called." << std::endl;
	this->_type = "Dog";
	this->_brain = new Brain();
}

// Copy constructor
Dog::Dog(const Dog& copy): AAnimal(copy)
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
		if (src._brain)
			this->_brain = new Brain(*src._brain);
		else
			this->_brain = NULL;
	}
	return (*this);
}

// Destructor
Dog::~Dog(void)
{
	delete this->_brain;
	std::cout << "Destructor of the Dog class called." << std::endl;
}

// Getters
void	Dog::getBrainContent(void) const
{
	std::cout << "___Dog's Brain___" << "\n";
	for (int i = 0; i < 100 && this->_brain->getIdea(i).length() > 0; i++)
		std::cout << "Idea " << i << ": '" << this->_brain->getIdea(i)
			<< "' saved at " << this->_brain->getIdeaAddress(i) << std::endl;
}

// Setters
void	Dog::setIdea(std::string idea, int i)
{
	this->_brain->setIdea(idea, i);
}

// Other member functions
void	Dog::makeSound(void) const
{
	std::cout << "An instance of type '" << this->_type << "' is barking."
		<< std::endl;
}

void	Dog::brainDump(void) const
{
	std::cout << "Dog's brain: " << this->_brain << std::endl;
}
