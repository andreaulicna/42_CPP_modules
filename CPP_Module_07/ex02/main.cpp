/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 09:35:17 by aulicna           #+#    #+#             */
/*   Updated: 2024/04/21 10:55:48 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>

int	main(void)
{
	std::cout << "Creating an empty array of ints...\n";
	Array<int> nothing;
	std::cout << "Printing the nothing array: ";
	nothing.printArr();
	std::cout << std::endl;

	std::cout << "Creating an array of 10 ints...\n";
	Array<int> something(10);
	std::cout << "Printing the something array: ";
	something.printArr();
	std::cout << std::endl;

	std::cout << "Creating an array of digits ...\n";
	Array<int> numbers(10);
	for (size_t i = 0; i < 10; i++)
		numbers[i] = i;
	std::cout << "Printing the numbers array: ";
	numbers.printArr();
	std::cout << std::endl;

	std::cout << "Testing copy constructor...\n";
	Array<int> testNumbers(numbers);
	std::cout << "Printing the testNumbers array: ";
	testNumbers.printArr();
	std::cout << "Replacing the numbers at indexes 3 and 5 in testNumbers..\n";
	testNumbers[3] = 42;
	testNumbers[5] = 42;
	std::cout << "Printing the numbers array: ";
	numbers.printArr();
	std::cout << "Printing the testNumbers array: ";
	testNumbers.printArr();
	std::cout << std::endl;

	std::cout << "Testing copy assignment operator...\n";
	Array<int> anotherTestNumbers(numbers);
	std::cout << "Printing the anotherTestNumbers array: ";
	anotherTestNumbers.printArr();
	std::cout << "Replacing the numbers at indexes 3 and 5 in anotherTestNumbers..\n";
	anotherTestNumbers[3] = 42;
	anotherTestNumbers[5] = 42;
	std::cout << "Printing the numbers array: ";
	numbers.printArr();
	std::cout << "Printing the anotherTestNumbers array: ";
	anotherTestNumbers.printArr();
	std::cout << std::endl;

	std::cout << "Throwing exceptions when accessing invalid indexes...\n";
	std::cout << "Negative index: ";
	try
	{
		anotherTestNumbers[-4];
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "Bigger than array's size index: ";
	try
	{
		anotherTestNumbers[42];
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;

	std::cout << "Testing size function...\n";
	std::cout << "nothing: " << nothing.size() << std::endl;
	std::cout << "something: " << something.size() << std::endl;
	std::cout << "numbers: " << numbers.size() << std::endl;
	std::cout << "testNumbers: " << testNumbers.size() << std::endl;	
	std::cout << "anotherTestNumbers: " << anotherTestNumbers.size() << std::endl;	
	return (0);
}
