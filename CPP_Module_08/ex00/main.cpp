/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 16:22:58 by aulicna           #+#    #+#             */
/*   Updated: 2024/04/21 16:49:04 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int	main(void)
{
	std::vector<int>	numbers;
	std::vector<int>	randomNumbers;

	for (int i = 0; i < 15; i++)
		numbers.push_back(i);
	for (std::vector<int>::iterator it = numbers.begin(); it != numbers.end(); it++)
	{
		std::cout << *it;
		if (it + 1 != numbers.end())
			std::cout << ", ";
	}
	std::cout << std::endl;
	try
	{
		easyfind(numbers, 2);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		easyfind(numbers, 14);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		easyfind(numbers, 42);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		easyfind(numbers, -42);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;

	srand(time(0));
	for (int i = 0; i < 15; i++)
		randomNumbers.push_back(rand() % 42);
	for (std::vector<int>::iterator it = randomNumbers.begin(); it != randomNumbers.end(); it++)
	{
		std::cout << *it;
		if (it + 1 != randomNumbers.end())
			std::cout << ", ";
	}
	std::cout << std::endl;
	try
	{
		easyfind(randomNumbers, 2);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		easyfind(randomNumbers, 14);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		easyfind(randomNumbers, 42);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		easyfind(randomNumbers, -42);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return(0);
}