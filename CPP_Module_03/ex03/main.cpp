/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 16:59:32 by aulicna           #+#    #+#             */
/*   Updated: 2024/03/25 14:22:30 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.class.hpp"

int main(void)
{
	ClapTrap	cla("Cla");
	ScavTrap	sca("Sca");
	FragTrap	fra("Fra");
	DiamondTrap	dia("Dia");

	std::cout << cla;
	std::cout << sca;
	std::cout << fra;
	std::cout << dia;
	dia.whoAmI();

	cla.attack("Victim");
	sca.attack("Victim");
	fra.attack("Victim");
	dia.attack("Victim");
	std::cout << cla;
	std::cout << sca;
	std::cout << fra;
	std::cout << dia;

	cla.takeDamage(10);
	sca.takeDamage(10);
	fra.takeDamage(10);
	dia.takeDamage(10);
	std::cout << cla;
	std::cout << sca;
	std::cout << fra;
	std::cout << dia;

	cla.beRepaired(3);
	sca.beRepaired(3);
	fra.beRepaired(3);
	dia.beRepaired(3);
	std::cout << cla;
	std::cout << sca;
	std::cout << fra;
	std::cout << dia;

	sca.guardGate();
	fra.highFivesGuys();
	dia.whoAmI();
	return (0);
}
