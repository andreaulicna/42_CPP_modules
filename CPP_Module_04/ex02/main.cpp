/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 10:39:40 by aulicna           #+#    #+#             */
/*   Updated: 2024/03/27 12:17:36 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.class.hpp"
#include "Dog.class.hpp"
#include "Cat.class.hpp"

int main()
{
	{
		// Subject main
		std::cout << "SUBJECT MAIN" << std::endl;
		const AAnimal* dog = new Dog();
		const AAnimal* cat = new Cat();

		cat->brainDump();
		dog->brainDump();

		delete dog;
		delete cat;
		std::cout << std::endl;
	}
	{
		// Array with 10 dogs and 10 cats
		std::cout << "ARRAY WITH 10 DOGS AND 10 CATS" << std::endl;
		int				array_size = 20;
		const AAnimal	*animals[array_size];

		for (int i = 0; i < array_size / 2; i++)
			animals[i] = new Dog();
		for (int i = 10; i < array_size; i++)
			animals[i] = new Cat();
		for (int i = 0; i < array_size; i++)
		{
			std::cout << i << " ";
			animals[i]->brainDump();
		}
		for (int i = 0; i < array_size; i++)
			delete animals[i];
		std::cout << std::endl;
	}
	{
		// Deep copies of Cats
		std::cout << "DEEP COPIES OF CATS" << std::endl;
		Cat	*smartCat = new Cat();

		smartCat->setIdea("It's a nice day.", 0);
		smartCat->setIdea("Sun is out.", 1);
		smartCat->getBrainContent();
		smartCat->brainDump();

		Cat *anotherSmartCat = new Cat(*smartCat);
		anotherSmartCat->setIdea("Tadaaaa!", 2);
		anotherSmartCat->getBrainContent();
		anotherSmartCat->brainDump();
		anotherSmartCat->setIdea("Tadaaaa!", 0);
		anotherSmartCat->getBrainContent();
		anotherSmartCat->brainDump();
		smartCat->getBrainContent();
		smartCat->brainDump();

		delete smartCat;
		delete anotherSmartCat;	
		std::cout << std::endl;
	}
	{
		// Deep copies of Dogs
		std::cout << "DEEP COPIES OF DOGS" << std::endl;
		Dog	*smartDog = new Dog();

		smartDog->setIdea("It's a nice day.", 0);
		smartDog->setIdea("Sun is out.", 1);
		smartDog->getBrainContent();
		smartDog->brainDump();

		Dog *anotherSmartDog = new Dog(*smartDog);
		anotherSmartDog->setIdea("Tadaaaa!", 2);
		anotherSmartDog->getBrainContent();
		anotherSmartDog->brainDump();
		anotherSmartDog->setIdea("Tadaaaa!", 0);
		anotherSmartDog->getBrainContent();
		anotherSmartDog->brainDump();
		smartDog->getBrainContent();
		smartDog->brainDump();

		delete smartDog;
		delete anotherSmartDog;
	}
	{
		// AAnimal is a pure virtual class (abstract class), which means
		// it cannot be instantiated, and so the below won't compile
		//const AAnimal	*pureVirtualAnimal = new AAnimal();
	}
	return 0;
}
