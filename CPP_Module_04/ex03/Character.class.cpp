/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 13:01:09 by aulicna           #+#    #+#             */
/*   Updated: 2024/03/27 21:54:27 by aulicna          ###   ########.fr       */
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
	*this = copy;
}

// Copy assignment operator overload
Character	&Character::operator = (const Character &src)
{
	(void) src;
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
	while (this->_inventory[i])
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


//void Character::unequip(int idx)
//{
//
//}

void Character::use(int idx, ICharacter& target)
{
	if (idx > 3 || idx < 0)
		std::cerr << "You're looking in a wrong place, this is not the Character's '" << this->getName() << "' inventory" << std::endl;
	if (this->_inventory[idx])
		this->_inventory[idx]->use(target);
	else
		std::cerr << "Sort of right place, but the Character '" << this->getName() << "' doesn't carry as many materias." << std::endl;
	
}
