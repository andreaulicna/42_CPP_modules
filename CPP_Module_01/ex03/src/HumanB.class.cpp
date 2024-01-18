/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 20:15:09 by aulicna           #+#    #+#             */
/*   Updated: 2024/01/18 20:58:18 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/HumanB.class.hpp"
#include <iostream>

HumanB::HumanB(std::string name): _name(name), _weapon(NULL)
{
	std::cout << "HumanB created." << std::endl;
	return ;
}

HumanB::~HumanB()
{
	std::cout << "HumanB destroyed." << std::endl;
	return ;
}

/**
* @fn void setWeapon(Weapon &weapon)
* @brief Sets the weapon for the HumanB object.
*
* The weapon is passed by reference, so that the function can save a pointer
* to it by taking the address of the reference. Reference in its simplest
* form is an another name for the original object.
*/
void	HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}

void	HumanB::attack(void) const
{
	std::cout << this->_name << " attacks with their "
		<< this->_weapon->getType() << std::endl;
}