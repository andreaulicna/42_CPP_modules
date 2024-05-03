/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 09:35:17 by aulicna           #+#    #+#             */
/*   Updated: 2024/05/03 11:28:00 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void	addTen(double &num)
{
	num += 10;	
}

int	main(void)
{
	int			arrInts[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	float		arrFloats[] = {-42.0f, 42.0f, 0.0f};
	double		arrDoubles[] = {-4.0, 4.0, 0.0};
	std::string	arrStrings[] = {"Hello", "World", "42"};

	std::cout << "Print ints via for loop:\n"; 
	for (int i = 0; i < 9; i++)
		std::cout << arrInts[i] << ", ";
	std::cout << arrInts[9] << std::endl;
	std::cout << "Print ints via iter:\n"; 
	::iter(arrInts, 9, ::myPrint<int>);
	std::cout << arrInts[9] << std::endl;
	std::cout << "Print floats via iter:\n"; 
	::iter(arrFloats, 2, ::myPrint<float>);
	std::cout << arrFloats[2] << std::endl;
	std::cout << "Print doubles via iter:\n"; 
	::iter(arrDoubles, 2, ::myPrint<double>);
	std::cout << arrDoubles[2] << std::endl;
	std::cout << "Add ten to each element and then print doubles via iter:\n"; 
	::iter(arrDoubles, 3, addTen);
	::iter(arrDoubles, 2, ::myPrint<double>);
	std::cout << arrDoubles[2] << std::endl;
	std::cout << "Print strings via iter:\n"; 
	::iter(arrStrings, 2, ::myPrint<std::string>);
	std::cout << arrStrings[2] << std::endl;
	
	return (0);
}