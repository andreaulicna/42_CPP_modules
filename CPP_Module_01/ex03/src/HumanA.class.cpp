/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 19:31:36 by aulicna           #+#    #+#             */
/*   Updated: 2024/01/18 20:20:54 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/HumanA.class.hpp"
#include <iostream>

HumanA::HumanA(std::string name, Weapon &weapon): _name(name), _weapon(weapon)
{
	std::cout << "HumanA created." << std::endl;
	return ;
}

HumanA::~HumanA()
{
	std::cout << "HumanA destroyed." << std::endl;
	return ;
}

void	HumanA::attack(void) const
{
	std::cout << this->_name << " attacks with their "
		<< this->_weapon.getType() << std::endl;
}