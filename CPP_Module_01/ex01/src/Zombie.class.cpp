/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 11:17:49 by aulicna           #+#    #+#             */
/*   Updated: 2024/01/19 20:38:16 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Zombie.hpp"
#include <iostream>

/* Constructor */
Zombie::Zombie(void)
{
	std::cout << "A zombie just woke up from 1000 years of sleep." << std::endl;
}
Zombie::Zombie(std::string name): _name(name)
{
	std::cout << this->_name << " just woke up after 1000 years of sleep."
		<< std::endl;
}

/* Destructor */
Zombie::~Zombie()
{
	std::cout << this->_name
		<< " has done enough damaged and went back to sleep." << std::endl;
}

void	Zombie::setName(std::string name)
{
	this->_name = name;
}

/**
 * @brief	Prints a message formated as [name]: BraiiiiiiinnnzzzZ...
*/
void	Zombie::announce(void) const
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
