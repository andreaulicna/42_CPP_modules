/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 11:34:29 by aulicna           #+#    #+#             */
/*   Updated: 2024/01/13 11:50:02 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Zombie.hpp"

int	main(void)
{
	Zombie	*Arthur;

	Arthur = newZombie("Arthur Dent");
	randomChump("Zaphod Beeblebrox");
	delete Arthur;
	return (0);
}