/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 12:19:50 by aulicna           #+#    #+#             */
/*   Updated: 2024/01/07 12:46:37 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Sample.class.hpp"

int	main(void)
{
	Sample	instance;
	Sample	other;

	std::cout << std::endl;
	std::cout << "***Accessors***" << std::endl;
	instance.setFoo(42);
	std::cout << "instance.getFoo(): " << instance.getFoo() << std::endl;
	instance.setFoo(-42);
	std::cout << "instance.getFoo(): " << instance.getFoo() << std::endl;
	std::cout << std::endl;

	std::cout << "***Comparisons***" << std::endl;
	instance.setFoo(42);
	other.setFoo(42);

	if (&instance == &instance)
		std::cout << "instance and instance are physically equal." << std::endl;
	else
		std::cout << "instance and instance are NOT physically equal." << std::endl;
	if (&instance == &other)
		std::cout << "instance and other are physically equal." << std::endl;
	else
		std::cout << "instance and other are NOT physically equal." << std::endl;
	
	if (instance.compare(&instance) == 0)
		std::cout << "instance and instance are structurally equal." << std::endl;
	else
		std::cout << "instance and instance are NOT structurally equal." << std::endl;
	if (instance.compare(&other) == 0)
		std::cout << "instance and other are structurally equal." << std::endl;
	else
		std::cout << "instance and other are NOT structurally equal." << std::endl;

	return (0);
}
