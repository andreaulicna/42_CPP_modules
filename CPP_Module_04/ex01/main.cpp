/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 10:39:40 by aulicna           #+#    #+#             */
/*   Updated: 2024/03/26 13:39:09 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.class.hpp"
#include "Dog.class.hpp"
#include "Cat.class.hpp"

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	delete j;//should not create a leak
	delete i;

	return 0;
}
