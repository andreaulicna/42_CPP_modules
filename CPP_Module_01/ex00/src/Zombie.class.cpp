/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 11:17:49 by aulicna           #+#    #+#             */
/*   Updated: 2024/01/13 11:58:48 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Zombie.hpp"
#include <iostream>

/* Constructor */
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

/**
 * @brief	Prints a message formated as [name]: BraiiiiiiinnnzzzZ...
*/
void	Zombie::announce(void)
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
