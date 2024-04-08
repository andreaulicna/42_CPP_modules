/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.class.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 18:20:36 by aulicna           #+#    #+#             */
/*   Updated: 2024/04/08 19:40:51 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.class.hpp"

// Default constructor
MateriaSource::MateriaSource(void)
{
	std::cout << "Default constructor of the MateriaSource class called."
		<< std::endl;
	for (int i = 0; i < 4; i++)
		this->_learnInventory[i] = NULL;
}

// Copy constructor
MateriaSource::MateriaSource(const MateriaSource& copy)
{
	std::cout << "Constructor overload of the MateriaSource class called."
		<< std::endl;
	for (int i = 0; i < 4; i++)
		if (copy._learnInventory[i])
			this->_learnInventory[i] = copy._learnInventory[i]->clone();
}

// Copy assignment operator overload
MateriaSource	&MateriaSource::operator = (const MateriaSource &src)
{
	std::cout << "Copy assignment operator of the MateriaSource class called."
		<< std::endl;
	for (int i = 0; i < 4; i++)
		this->_learnInventory[i] = src._learnInventory[i];
	return (*this);
}

// Destructor
MateriaSource::~MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_learnInventory[i])
		{
			delete this->_learnInventory[i];
			this->_learnInventory[i] = NULL;
		}
	}
}

// Other member functions
void		MateriaSource::learnMateria(AMateria *materia)
{
	int	i;

	if (materia)
	{
		i = 0;
		while (i < 4 && this->_learnInventory[i])
			i++;
		if (i == 4)
		{
			std::cerr << "No more materias can be learned." << std::endl;
			return ;
		}
		this->_learnInventory[i] = materia;
		std::cout << "Learning process of '" << materia->getType()
			<< "' materia successfull." << std::endl;
	}
	else
		std::cerr << "Well, that's not a valid materia to learn." << std::endl;
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	AMateria	*createdMateria;
	int			i;

	i = 0;
	while (i < 4 && this->_learnInventory[i]
		&& this->_learnInventory[i]->getType() != type)
		i++;
	std::cout << "\n";
	if (i != 4 && this->_learnInventory[i])
	{
		createdMateria = this->_learnInventory[i]->clone();
		std::cout << "A new materia of type '" << createdMateria->getType()
			<< "' was created." << std::endl;
	}
	else
	{
		std::cerr << "A new materia wasn't created." << std::endl;
		createdMateria = NULL;
	}
	return (createdMateria);
}
