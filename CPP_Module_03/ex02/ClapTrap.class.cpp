/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.class.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:50:35 by aulicna           #+#    #+#             */
/*   Updated: 2024/03/25 14:11:01 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.class.hpp"

ClapTrap::ClapTrap(void): _name("Noname"), _hitPoints(10), _energyPoints(10),
	_attackDamage(0)
{
    std::cout << "Default constructor called for an instance named '"
		<< this->_name << "'" << std::endl; 
}

ClapTrap::ClapTrap(std::string name): _name(name), _hitPoints(10),
	_energyPoints(10), _attackDamage(0)
{
    std::cout << "Constructor called for an instance named '"
		<< this->_name << "'" << std::endl; 
}

ClapTrap::ClapTrap(const ClapTrap& copy)
{
    std::cout << "Copy constructor called for an instance named '"
		<< copy._name << "'" << std::endl; 
	*this = copy;
}

ClapTrap    &ClapTrap::operator = (const ClapTrap &src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
	{
		this->_name = src.getName();
		this->_hitPoints = src.getHitPoints();
		this->_energyPoints = src.getEnergyPoints();
		this->_attackDamage = src.getAttackDamage();
	}
	return (*this);
}

ClapTrap::~ClapTrap(void)
{
    std::cout << "Destructor called for an instance named '" << this->_name
		<< "'" << std::endl; 
}

// Getters
std::string	ClapTrap::getName(void) const
{
	return (this->_name);
}

int	ClapTrap::getHitPoints(void) const
{
	return (this->_hitPoints);
}

int	ClapTrap::getEnergyPoints(void) const
{
	return (this->_energyPoints);
}

int	ClapTrap::getAttackDamage(void) const
{
	return (this->_attackDamage);
}

void	ClapTrap::setAttackDamage(unsigned int amount)
{
	this->_attackDamage = amount;
}

void    ClapTrap::attack(const std::string& target)
{
	if (this->_energyPoints > 0 && this->_hitPoints > 0)
	{
		this->_energyPoints -= 1;
		std::cout << "ClapTrap '" << this->_name << "' attacks '" << target
			<< "' causing " << this->_attackDamage << " points of damage!"
			<< std::endl;
	}
	else
		std::cout << "ClapTrap '" << this->_name
			<< "' doesn't have enough energy and/or hit points to attack."
			<< std::endl;
}

void    ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints <= 0)
	{
		std::cout << "ClapTrap '" << this->_name
			<< "' is already dead, there is no point in attacking it more."
			<< std::endl;
		return ;
	}
	if (this->_hitPoints >= amount)
    	this->_hitPoints -= amount;
	else if (this->_hitPoints > 0)
		this->_hitPoints = 0;
    std::cout << "ClapTrap '" << this->_name
		<< "' suffered an attack, took damage of " << amount
		<< " hit points and now is at " << this->_hitPoints << " hit points."
		<< std::endl;
}

void    ClapTrap::beRepaired(unsigned int amount)
{
    if (this->_energyPoints > 0 && this->_hitPoints > 0)
    {
		this->_hitPoints += amount;
		this->_energyPoints -= 1;
		std::cout << "ClapTrap '" << this->_name << "' was repared with "
			<< amount << " hit points and now is at " << this->_hitPoints
			<< " hit points." << std::endl;
	}
	else
		std::cout << "ClapTrap '" << this->_name
		<< "' doesn't have enough energy and/ or hits points to repair itself."
		<< std::endl;
}

std::ostream &operator << (std::ostream &o, ClapTrap const &instance)
{
	o << "ClapTrap '" << instance.getName() << "' "
		<< "hit points (" << instance.getHitPoints() << "), "
		<< "energy points (" << instance.getEnergyPoints() << "), "
		<< "attack damage (" << instance.getAttackDamage() << ")." << std::endl;
	return (o);
}
