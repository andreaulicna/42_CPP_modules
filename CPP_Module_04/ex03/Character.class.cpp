/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 13:01:09 by aulicna           #+#    #+#             */
/*   Updated: 2024/03/27 23:06:38 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.class.hpp"

AMateria	*Character::_floor[100];

// Default constructor
Character::Character(void): ICharacter()
{
	std::cout << "Default constructor of the Character class called." << std::endl;
	this->_name = "Character";
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

// Constructor overloads
Character::Character(std::string name): ICharacter()
{
	std::cout << "Constructor overload of the Character class called." << std::endl;
	this->_name = name;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

// Copy constructor
Character::Character(const Character& copy)
{
	std::cout << "Copy constructor of the Character class called." << std::endl;
	this->_name = copy._name;
	for (int i = 0; i < 4; i++)
		if (copy._inventory[i])
			this->_inventory[i] = copy._inventory[i]->clone();
}

// Copy assignment operator overload
Character	&Character::operator = (const Character &src)
{
	std::cout << "Copy assignment operator of the Character class called."
		<< std::endl;
	if (this != &src)
	{
		this->_name = src._name;
		for (int i = 0; i < 4; i++)
		{
			if (this->_inventory[i])
				delete this->_inventory[i];
		}
		for (int i = 0; i < 4; i++)
			this->_inventory[i] = src._inventory[i]->clone();
	}
	return (*this);
}

// Destructor
Character::~Character(void)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
		{
			delete this->_inventory[i];
			this->_inventory[i] = NULL;
		}
	}
	std::cout << "Destructor of the Character class called." << std::endl;
}

// Getters
std::string const	&Character::getName() const
{
	return (this->_name);
}

void	Character::getInventory(void) const
{
	std::cout << "*** Character's '" << this->_name << "' inventory *** " << "\n";
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
			std::cout << i <<". Materia of type '" << this->_inventory[i]->getType() << "' carried at " << this->_inventory[i] << std::endl;
		else
			std::cout << i << ". Free space" << std::endl;
	}
}

// Other member functions
void Character::equip(AMateria* m)
{
	int	i;

	if (m->getIsEquipped())
	{
		std::cerr << "Character '" << this->_name << "' cannot steal a materia from someone else's inventory!" << std::endl;
		return ;
	}
	i = 0;
	while (i < 4 && this->_inventory[i])
		i++;
	if (i == 4)
	{
		std::cerr << "Character's '" << this->_name << "' inventory is full and no more materias can be added unless one is dropped." << std::endl;
		return ;
	}
	this->_inventory[i] = m;
	this->_inventory[i]->setIsEquipped(true);
	std::cout << "Character '" << this->_name << "' has been equipped with '" << m->getType() << "' materia." << std::endl;
}

void Character::unequip(int idx)
{
	int	i;

	i = 0;
	if (idx < 0 || idx > 3)
	{
		std::cerr << "You're looking in a wrong place for unequipping of a materia, this is not the Character's '" << this->getName() << "' inventory." << std::endl;
		return ;
	}
	if (this->_inventory[i])
	{
		while (i < 100 && this->_floor[i])
			i++;
		this->_floor[i] = this->_inventory[idx];
		this->_floor[i]->setIsEquipped(false);
		this->_inventory[idx] = NULL;
		std::cout << "Successfully unequipped Materia '" << this->_inventory[i]->getType() << "' from Character '" << this->getName() << "'." << std::endl;
	}
	else
		std::cerr << "Sort of right place, but the Character '" << this->getName() << "' doesn't carry a materia on this place of inventory." << std::endl;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx > 3 || idx < 0)
	{
		std::cerr << "You're looking in a wrong place to use a materia, this is not the Character's '" << this->getName() << "' inventory." << std::endl;
		return ;
	}
	if (this->_inventory[idx])
		this->_inventory[idx]->use(target);
	else
		std::cerr << "Sort of right place, but the Character '" << this->getName() << "' doesn't carry as many materias." << std::endl;
}

void	Character::sweepFloor(void)
{
	for (int i = 0; i < 100; i++)
	{
		if (_floor[i])
			delete _floor[i];
	}
}
