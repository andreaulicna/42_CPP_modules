/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 13:01:09 by aulicna           #+#    #+#             */
/*   Updated: 2024/04/08 19:39:54 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.class.hpp"

AMateria	*Character::_floor[FLOOR_CAPACITY];

// Default constructor
Character::Character(void): ICharacter()
{
	std::cout << "Default constructor of the Character class called."
		<< std::endl;
	this->_name = "Character";
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

// Constructor overloads
Character::Character(std::string name): ICharacter()
{
	std::cout
		<< "Constructor overload of the Character class for a Character named '"
		<< name << "' called." << std::endl;
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
	std::cout << "\n";
	std::cout << "*** Character's '" << this->_name << "' inventory ***" << "\n";
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
			std::cout << i <<". Materia of type '"
				<< this->_inventory[i]->getType() << "' carried at "
				<< this->_inventory[i] << std::endl;
		else
			std::cout << i << ". Free space" << std::endl;
	}
}

void	Character::getFloor(void)
{
	std::cout << "\n";
	if (_floor[0])
	{
		std::cout << "*** The Floor ***" << "\n";
		for (int i = 0; i < FLOOR_CAPACITY; i++)
		{
			if (_floor[i])
				std::cout << i <<". place of the Floor: '"
					<< _floor[i]->getType() << "' saved at " << _floor[i]
					<< std::endl;
		}
	}
	else
		std::cout << "The Floor is completely empty at the moment."
			<< std::endl;
}

// Other member functions
void Character::equip(AMateria* m)
{
	int	i;
	int	i_floor;

	std::cout << "\n";
	if (!m)
	{
		std::cerr << "Well, that's not a valid materia to equip anyone with."
			<< std::endl;
		return ;
	}
	if (m->getIsEquipped())
	{
		std::cerr << "Character '" << this->_name
			<< "' cannot steal a materia from someone else's inventory!"
				<< std::endl;
		return ;
	}
	i = 0;
	while (i < 4 && this->_inventory[i])
		i++;
	if (i == 4)
	{
		std::cerr << "Character's '" << this->_name
			<< "' inventory is full and no more materias can be added unless "
			<< "one is dropped first." << std::endl;
		return ;
	}
	i_floor = 0;
	while (i_floor < FLOOR_CAPACITY)
	{
		if (this->_floor[i_floor] == m)
		{
			this->_inventory[i] = m;
			this->_inventory[i]->setIsEquipped(true);
			this->_floor[i_floor] = NULL;
			std::cout << "Character '" << this->_name << "' has picked up '"
				<< m->getType() << "' materia from the floor." << std::endl;
			return ;
		}
		i_floor++;
	}
	this->_inventory[i] = m;
	this->_inventory[i]->setIsEquipped(true);
	std::cout << "Character '" << this->_name << "' has been equipped with '"
		<< m->getType() << "' materia." << std::endl;
}

void Character::unequip(int idx)
{
	int	i;

	std::cout << "\n";
	i = 0;
	if (idx < 0 || idx > 3)
	{
		std::cerr << "You're looking in a wrong place for unequipping "
			<< "of a materia, this is not the Character's '" << this->getName()
			<< "' inventory." << std::endl;
		return ;
	}
	if (this->_inventory[i])
	{
		while (i < FLOOR_CAPACITY && this->_floor[i])
			i++;
		if (i == FLOOR_CAPACITY)
		{
			std::cerr << "There is no more space on the floor! "
				<< "Let's delete a materia that has been laying there "
				<< "the longest." << std::endl;
			delete _floor[0];
			for (int i = 0; i < FLOOR_CAPACITY; i++)
				_floor[i] = _floor[i + 1];
			i = FLOOR_CAPACITY - 1;
		}
		this->_floor[i] = this->_inventory[idx];
		this->_floor[i]->setIsEquipped(false);
		this->_inventory[idx] = NULL;
		std::cout << "Successfully unequipped Materia '"
			<< this->_floor[i]->getType() << "' from Character '"
			<< this->getName() << "'." << std::endl;
	}
	else
		std::cerr << "Sort of the right place (unequip), but the Character '"
			<< this->getName() << "' doesn't carry a materia at this place "
			<< "of the inventory." << std::endl;
}

void Character::use(int idx, ICharacter& target)
{
	std::cout << "\n";
	if (idx > 3 || idx < 0)
	{
		std::cerr << "You're looking in a wrong place to use a materia, "
			<< "this is not the Character's '" << this->getName() << "' inventory."
			<< std::endl;
		return ;
	}
	if (this->_inventory[idx])
		this->_inventory[idx]->use(target);
	else
		std::cerr << "Sort of right place (use), but the Character '"
			<< this->getName() << "' doesn't carry as many materias."
			<< std::endl;
}

void	Character::sweepFloor(void)
{
	for (int i = 0; i < FLOOR_CAPACITY; i++)
	{
		if (_floor[i])
			delete _floor[i];
	}
}
