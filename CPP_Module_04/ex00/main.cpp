/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 10:39:40 by aulicna           #+#    #+#             */
/*   Updated: 2024/03/26 16:38:40 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.class.hpp"
#include "WrongAnimal.class.hpp"
#include "Dog.class.hpp"
#include "Cat.class.hpp"
#include "WrongCat.class.hpp"

int main()
{
	{
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();

		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); //will output the cat sound!
		j->makeSound();
		meta->makeSound();
		delete meta;
		delete j;
		delete i;
		std::cout << std::endl;
	}
	{
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const WrongAnimal* i = new WrongCat();

		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); //will NOT output the cat sound!
		j->makeSound();
		meta->makeSound();
		delete meta;
		delete j;
		delete i;
		std::cout << std::endl;
	}
	{
		const WrongCat* i = new WrongCat();

		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); //will output the cat sound bcs it's WrongCat pointer!
		delete i;
	}
	return 0;
}
