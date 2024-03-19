/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.class.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 18:04:47 by aulicna           #+#    #+#             */
/*   Updated: 2024/03/19 19:07:42 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.class.hpp"

// Default constructor
ScavTrap::ScavTrap(void): ClapTrap()
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	this->_onGuard = false;
    std::cout << "ScavTrap default constructor called for an instance named '"
		<< this->_name << "'" << std::endl; 
}

// Consturctor overloads
ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	this->_onGuard = false;
    std::cout << "ScavTrap constructor called for an instance named '"
		<< this->_name << "'" << std::endl; 
}

// Copy constructor
ScavTrap::ScavTrap(const ScavTrap& copy): ClapTrap(copy)
{
	std::cout << "ScavTrap copy constructor called for an instance named '"
		<< copy.getName() << "'" << std::endl; 

}

// Copy assignment operator overload
ScavTrap	&ScavTrap::operator = (const ScavTrap &src)
{
	std::cout << "ScavTrap copy assignment operator called" << std::endl;
	if (this != &src)
	{
		this->_name = src.getName();
		this->_hitPoints = src.getHitPoints();
		this->_energyPoints = src.getEnergyPoints();
		this->_attackDamage = src.getAttackDamage();
	}
	return *this;
}

// Destructor
ScavTrap::~ScavTrap(void)
{
    std::cout << "ScavTrap destructor called for an instance named '"
		<< this->_name << "'" << std::endl; 
}

// Getters
bool	ScavTrap::getOnGuard(void) const
{
	return (this->_onGuard);
}

void	ScavTrap::attack(const std::string &target)
{
	if (this->_energyPoints > 0 && this->_hitPoints > 0)
	{
		this->_energyPoints -= 1;
		std::cout << "ScavTrap '" << this->_name << "' fired at '" << target
			<< "' causing " << this->_attackDamage << " points of damage!"
			<< std::endl;
	}
	else
		std::cout << "ScavTrap '" << this->_name
			<< "' is too exhausted (no energy and/ or hit points) "
			<< "to fire another attack." << std::endl;
}

void	ScavTrap::guardGate(void)
{
	if (this->_onGuard == false)
	{
		this->_onGuard = true;
		std::cout << "ScavTrap '" << this->_name
			<< "' is now in gate keeper mode." << std::endl;
	}
	else
		std::cout << "ScavTrap '" << this->_name
			<< "' has already been in gate keeper mode." << std::endl;
}
std::ostream &operator << (std::ostream &o, ScavTrap const &instance)
{
	o << "ScavTrap '" << instance.getName() << "' "
		<< "hit points (" << instance.getHitPoints() << "), "
		<< "energy points (" << instance.getEnergyPoints() << "), "
		<< "attack damage (" << instance.getAttackDamage() << "), "
		<< "gate keeper mode (" << instance.getOnGuard() << ")." << std::endl;
	return (o);
}
