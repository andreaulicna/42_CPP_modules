/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.class.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 19:11:21 by aulicna           #+#    #+#             */
/*   Updated: 2024/03/25 14:10:44 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.class.hpp"

// Default constructor
FragTrap::FragTrap(void): ClapTrap()
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap default constructor called for an instance named '"
		<< this->_name << "'" << std::endl; 
}

// Constructor overloads
FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
    std::cout << "FragTrap constructor called for an instance named '"
		<< this->_name << "'" << std::endl; 
}

// Copy constructor
FragTrap::FragTrap(const FragTrap& copy): ClapTrap(copy)
{
	std::cout << "FragTrap copy constructor called for an instance named '"
		<< copy.getName() << "'" << std::endl; 
	*this = copy;
}

// Copy assignment operator overload
FragTrap	&FragTrap::operator = (const FragTrap &src)
{
	std::cout << "FragTrap copy assignment operator called" << std::endl;
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
FragTrap::~FragTrap(void)
{
    std::cout << "FragTrap destructor called for an instance named '"
		<< this->_name << "'" << std::endl; 
}

std::ostream &operator << (std::ostream &o, FragTrap const &instance)
{
	o << "FragTrap '" << instance.getName() << "' "
		<< "hit points (" << instance.getHitPoints() << "), "
		<< "energy points (" << instance.getEnergyPoints() << "), "
		<< "attack damage (" << instance.getAttackDamage() << "), " << std::endl;
	return (o);
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap '" << this->_name << "' requests a high five :)"
		<< std::endl;
}