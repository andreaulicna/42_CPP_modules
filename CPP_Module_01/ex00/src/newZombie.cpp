/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 11:32:32 by aulicna           #+#    #+#             */
/*   Updated: 2024/01/13 11:58:34 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Zombie.hpp"

/**
 * @brief	Creates a zombie by allocing it on the heap, naming it and returning
 * a pointer to it to be used outside of this function scope.
 * 
 * The memory needs to be freed using the delete keyword on the returned object.
 * 
 * @param	name	name to assign to the zombie
 * @return	*Zombie	dynamically allocated object of the Zombie class
*/
Zombie	*newZombie(std::string name)
{
	Zombie	*zombie;

	zombie = new Zombie(name);
	return (zombie);
}