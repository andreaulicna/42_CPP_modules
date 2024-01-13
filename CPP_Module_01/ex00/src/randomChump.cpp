/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 11:32:51 by aulicna           #+#    #+#             */
/*   Updated: 2024/01/13 11:59:22 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Zombie.hpp"

/**
 * @brief	Creates a zombie on the stack, names it and the zombie announces
 * itself.
 * 
 * Once the control of the program is return to the function that called this
 * one, the Zombie destructor is called.
 * 
 * @param	name	name to assign to the zombie
*/
void	randomChump(std::string name)
{
	Zombie	randomChump = Zombie(name);

	randomChump.announce();
}