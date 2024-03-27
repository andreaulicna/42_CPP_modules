/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 12:57:33 by aulicna           #+#    #+#             */
/*   Updated: 2024/03/27 21:53:41 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.class.hpp"
#include "Ice.class.hpp"
#include "Character.class.hpp"

int main(void)
{
	{
		AMateria	*ice = new Ice();
		Character	*john = new Character("John");
		Character	*ben = new Character("Ben");

		std::cout << ice->getIsEquipped() << std::endl;
		john->equip(ice);
		std::cout << ice->getIsEquipped() << std::endl;
		john->use(0, *ben);

		delete john;
		delete ben;
	}
	{
		// Subject main
	//	IMateriaSource* src = new MateriaSource();
	//	src->learnMateria(new Ice());
	//	src->learnMateria(new Cure());
	//
	//	ICharacter* me = new Character("me");
	//
	//	AMateria* tmp;
	//	tmp = src->createMateria("ice");
	//	me->equip(tmp);
	//	tmp = src->createMateria("cure");
	//	me->equip(tmp);
	//
	//	ICharacter* bob = new Character("bob");
	//
	//	me->use(0, *bob);
	//	me->use(1, *bob);
	//
	//	delete bob;
	//	delete me;
	//	delete src;
	//	
	}
	{
		// AMateria and Ice constructors testing
	//	Ice	*ice = new Ice();

	//	std::cout << ice->getIsEquipped() << std::endl;
	//	ice->setIsEquipped(true);
	//	std::cout << ice->getIsEquipped() << std::endl;

	//	AMateria	*ice2 = new Ice(*ice);
	//	std::cout << ice2->getIsEquipped() << std::endl;
	

	//	AMateria	*ice4 = new Ice();
	//	AMateria	*ice3;
	//	ice4->setIsEquipped(true);
	//	ice3 = ice4;
	//	std::cout << ice3->getIsEquipped() << std::endl;

	//	delete ice;
	//	delete ice2;
	//	delete ice4;
	}
	return (0);
}
