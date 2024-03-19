/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 16:59:32 by aulicna           #+#    #+#             */
/*   Updated: 2024/03/19 19:29:22 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.class.hpp"

int main(void)
{
//	EX00
//	ClapTrap    clap("Clap");
//	ClapTrap    trap("Trap");
//
//	std::cout << clap;
//	std::cout << trap;
//	clap.setAttackDamage(5);
//	trap.setAttackDamage(7);
//	clap.attack("Trap");
//	trap.takeDamage(clap.getAttackDamage());
//	clap.attack("Trap");
//	trap.takeDamage(clap.getAttackDamage());
//	clap.attack("Trap");
//	trap.takeDamage(clap.getAttackDamage());

// Change hit points to 20 in the constructor to have the below make a point
//	ClapTrap   		clap("Clap");
//	ClapTrap    	trap("Trap");
//	unsigned int	check;
//
//	std::cout << clap;
//	std::cout << trap;
//	clap.setAttackDamage(1);
//	trap.setAttackDamage(7);
//	check = clap.getEnergyPoints();
//	for (unsigned int i = 0; i < 12; i++)
//	{
//		clap.attack("Trap");
//		if (check > i)
//			trap.takeDamage(clap.getAttackDamage());
//	}
//	std::cout << clap;
//	std::cout << trap;
//	return (0);

//	EX01
//	ScavTrap	scav("Scav");
//	ScavTrap	trap("Trap");
//
//	std::cout << scav;
//	std::cout << trap;
//	scav.attack("Trap");
//	trap.takeDamage(scav.getAttackDamage());
//	scav.attack("Trap");
//	trap.takeDamage(scav.getAttackDamage());
//	scav.attack("Trap");
//	trap.takeDamage(scav.getAttackDamage());
//	trap.beRepaired(3);
//
//	ScavTrap	scav("Scav");
//	ScavTrap	trap("Trap");
//	unsigned int	check;
//
//	std::cout << scav;
//	std::cout << trap;
//	check = trap.getEnergyPoints();
//	for (unsigned int i = 0; i < 52; i++)
//	{
//		trap.attack("Scav");
//		if (check > i)
//			scav.takeDamage(trap.getAttackDamage());
//	}

//	EX02
	FragTrap	frag("Frag");
	FragTrap	trap("Trap");

	std::cout << frag;
	std::cout << trap;
	frag.attack("Trap");
	trap.takeDamage(frag.getAttackDamage());
	frag.attack("Trap");
	trap.takeDamage(frag.getAttackDamage());
	frag.attack("Trap");
	trap.takeDamage(frag.getAttackDamage());
	trap.beRepaired(50);
	frag.highFivesGuys();
	return (0);
}
