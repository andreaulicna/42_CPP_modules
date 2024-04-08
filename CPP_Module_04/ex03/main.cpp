/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 12:57:33 by aulicna           #+#    #+#             */
/*   Updated: 2024/04/08 19:31:45 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.class.hpp"
#include "Ice.class.hpp"
#include "Cure.class.hpp"
#include "MateriaSource.class.hpp"
#include "Character.class.hpp"

int main(void)
{
	{
		// Subject main
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
	
		ICharacter* me = new Character("me");
	
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
	
		ICharacter* bob = new Character("bob");
	
		me->use(0, *bob);
		me->use(1, *bob);
	
		delete bob;
		delete me;
		delete src;
	}
	{
//		// MateriaSource learning
//		IMateriaSource* src = new MateriaSource();
//		AMateria	*ice1 = new Ice();
//
//		src->learnMateria(new Ice());
//		src->learnMateria(new Cure());
//		src->learnMateria(new Cure());
//		src->learnMateria(new Cure());
//		src->learnMateria(ice1);
//
//		delete ice1;
//		delete src;
	}
	{
//		// Floor capacity
//		ICharacter	*john = new Character("John");
//		ICharacter	*ben = new Character("Ben");
//		AMateria *tmp_materia;
//
//		for (int i = 0; i < 100; i++)
//		{
//			tmp_materia = new Cure();
//			std::cout << "\n" << i << ". ";
//			john->equip(tmp_materia);
//			john->unequip(0);
//		}
//		Character::getFloor();
//		tmp_materia = new Cure();
//		ben->equip(tmp_materia);
//		ben->getInventory();
//		ben->unequip(0);
//		Character::getFloor();
//
//		delete john;
//		delete ben;
//		Character::sweepFloor();
	}
	{
//		// Character unequip, sweep floor and use
//		AMateria	*ice1 = new Ice();
//		AMateria	*ice2 = new Ice();
//		AMateria	*cure1 = new Cure();
//		AMateria	*cure2 = new Cure();
//		AMateria	*cure3 = new Cure();
//		ICharacter	*john = new Character("John");
//		ICharacter	*ben = new Character("Ben");
//
//		Character::getFloor();
//		john->equip(ice1);
//		john->equip(ice2);
//		john->use(0, *ben);
//		john->use(4, *ben);
//		john->use(3, *ben);
//		john->equip(cure1);
//		john->equip(cure2);
//		john->getInventory();
//		john->unequip(1);
//		Character::getFloor();
//		john->getInventory();
//		john->unequip(5);
//		john->unequip(-8);
//		john->unequip(2);
//		Character::getFloor();
//		john->getInventory();
//		ben->equip(ice1);
//		ben->equip(ice2);
//		ben->equip(cure3);
//		ben->use(-5, *john);
//		ben->use(0, *john);
//		ben->use(1, *john);
//		ben->getInventory();
//		Character::getFloor();
//
//		delete john;
//		delete ben;
//		Character::sweepFloor();
	}
	{
//		// Character equip limits
//		AMateria	*ice1 = new Ice();
//		AMateria	*ice2 = new Ice();
//		AMateria	*ice3 = new Ice();
//		AMateria	*ice4 = new Ice();
//		AMateria	*ice5 = new Ice();
//		ICharacter	*john = new Character("John");
//		ICharacter	*ben = new Character("Ben");
//
//		std::cout << ice1->getIsEquipped() << std::endl;
//		john->equip(ice1);
//		std::cout << ice1->getIsEquipped() << std::endl;
//		john->use(2, *ben);
//		john->equip(ice2);
//		john->equip(ice3);
//		john->equip(ice4);
//		john->equip(ice5);
//		john->use(2, *ben);
//		john->use(-2, *ben);
//		john->use(5, *ben);
//
//		delete john;
//		delete ben;
//		delete ice5;
	}
	{
//		// Character copy constructor and assignment operator
//		AMateria	*ice1 = new Ice();
//		AMateria	*ice2 = new Ice();
//		AMateria	*ice3 = new Ice();
//		AMateria	*ice4 = new Ice();
//		Character	*john = new Character("John");
//
//		john->equip(ice1);
//		john->equip(ice2);
//		john->equip(ice3);
//		john->equip(ice4);
//		john->getInventory();
//		ICharacter	*ben = new Character(*john);
//		ben->getInventory();
//
//		delete john;
//		delete ben;
	}
	{
//		// AMateria and Ice constructors
//		Ice	*ice = new Ice();
//
//		std::cout << ice->getIsEquipped() << std::endl;
//		ice->setIsEquipped(true);
//		std::cout << ice->getIsEquipped() << std::endl;
//
//		AMateria	*ice2 = new Ice(*ice);
//		std::cout << ice2->getIsEquipped() << std::endl;
//	
//
//		AMateria	*ice4 = new Ice();
//		AMateria	*ice3;
//		ice4->setIsEquipped(true);
//		ice3 = ice4;
//		std::cout << ice3->getIsEquipped() << std::endl;
//
//		delete ice;
//		delete ice2;
//		delete ice4;
	}
	return (0);
}
