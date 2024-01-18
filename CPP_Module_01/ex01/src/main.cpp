/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 11:34:29 by aulicna           #+#    #+#             */
/*   Updated: 2024/01/13 12:59:08 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Zombie.hpp"

int	main(void)
{
	Zombie	*hitchhikers;
	int		N;

	N = 3;
	hitchhikers = zombieHorde(N, "Prefect");	
	delete [] hitchhikers;
	return (0);
}