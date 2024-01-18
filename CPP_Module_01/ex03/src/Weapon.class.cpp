/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:33:25 by aulicna           #+#    #+#             */
/*   Updated: 2024/01/18 19:53:28 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Weapon.class.hpp"
#include <iostream>

Weapon::Weapon(void)
{
	std::cout << "Weapon (without type) created." << std::endl;
	return ;
}

Weapon::Weapon(std::string type): _type(type)
{
	std::cout << "Weapon (with type) created." << std::endl;
	return ;
}

Weapon::~Weapon(void)
{
	std::cout << "Weapon destroyed." << std::endl;
	return ;
}

std::string const	&Weapon::getType(void) const
{
	return (this->_type);
}

void	Weapon::setType(std::string newType)
{
	this->_type = newType;
}
