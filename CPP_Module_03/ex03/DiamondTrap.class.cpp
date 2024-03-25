/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.class.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 15:45:59 by aulicna           #+#    #+#             */
/*   Updated: 2024/03/25 14:26:16 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.class.hpp"

// Default constructor
DiamondTrap::DiamondTrap(void): ScavTrap(), FragTrap()
{
	ScavTrap	tmpScavTrap;

	this->_name = "Noname";
	ClapTrap::_name = _name + "_clap_name";
	this->_energyPoints = tmpScavTrap.getEnergyPoints();
	std::cout << "DiamondTrap default constructor called for an instance named '"
		<< this->_name << "'" << std::endl; 
}

// Constructor overloads
DiamondTrap::DiamondTrap(std::string name): ScavTrap(name), FragTrap(name)
{
	ScavTrap	tmpScavTrap;

	this->_name = name;
	ClapTrap::_name = _name + "_clap_name";
	this->_energyPoints = tmpScavTrap.getEnergyPoints();
    std::cout << "DiamondTrap constructor called for an instance named '"
		<< this->_name << "'" << std::endl; 
}

// Copy constructor
DiamondTrap::DiamondTrap(const DiamondTrap& copy): ClapTrap(copy), ScavTrap(copy), FragTrap(copy)
{
	std::cout << "DiamondTrap copy constructor called for an instance named '"
		<< copy.getName() << "'" << std::endl; 
	*this = copy;
}

// Copy assignment operator overload
DiamondTrap	&DiamondTrap::operator = (const DiamondTrap &src)
{
	std::cout << "DiamondTrap copy assignment operator called" << std::endl;
	if (this != &src)
	{
		this->_name = src.getName();
		this->_hitPoints = src.getHitPoints();
		this->_energyPoints = src.getEnergyPoints();
		this->_attackDamage = src.getAttackDamage();
	}
	return (*this);
}

// Destructor
DiamondTrap::~DiamondTrap(void)
{
    std::cout << "DiamondTrap destructor called for an instance named '"
		<< this->_name << "'" << std::endl;
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "___WHO AM I___\n"
	<< "| name: " << this->_name << "\n"
		<< "| ClapTrap name: " << ClapTrap::_name
		<< "\n--------------" << std::endl;
}

std::ostream &operator << (std::ostream &o, DiamondTrap const &instance)
{
	o << "DiamondTrap '" << instance.getName() << "' "
		<< "hit points (" << instance.getHitPoints() << "), "
		<< "energy points (" << instance.getEnergyPoints() << "), "
		<< "attack damage (" << instance.getAttackDamage() << ")." << std::endl;
	return (o);
}