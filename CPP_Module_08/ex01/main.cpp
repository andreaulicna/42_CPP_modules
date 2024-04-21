/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 23:43:17 by aulicna           #+#    #+#             */
/*   Updated: 2024/04/22 00:46:38 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.class.hpp"

int	main(void)
{
	std::cout << "__SUBJECT MAIN__\n"; 
	try
	{
		Span	sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		sp.printNumbers();
		std::cout << "----------------\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "\nJust adding numbers...\n";
	try
	{
		Span	sp = Span(15);
		
		sp.printNumbers();
		sp.addNumber(42);
		sp.printNumbers();
		sp.addManyMembers(1, 5);
		sp.printNumbers();
		sp.addManyMembersWithSpan(10, 20, 2);
		sp.printNumbers();
		sp.addNumber(42);
		sp.printNumbers();
		std::cout << "----------------\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "\nJust adding numbers (reverse order in addWithSpan)...\n";
	try
	{
		Span	sp = Span(15);
		
		sp.printNumbers();
		sp.addNumber(42);
		sp.printNumbers();
		sp.addManyMembers(1, 5);
		sp.printNumbers();
		sp.addManyMembersWithSpan(20, 10, 2);
		sp.printNumbers();
		std::cout << "----------------\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "\nJust adding numbers... but there is no space :(\n";
	try
	{
		Span	sp = Span(3);

		sp.addManyMembers(1, 5);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "\nJust adding numbers (via addWithSpan)... "
		<< "but there is no space :(\n";
	try
	{
		Span	sp = Span(3);

		sp.addManyMembersWithSpan(10, 20, 2);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "\nSpan 0 is sort of useless...\n";
	try
	{
		Span	sp = Span(3);

		sp.addManyMembersWithSpan(10, 20, 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "\nSpan 0 again...now in constructor\n";
	try
	{
		Span	sp = Span(0);

		sp.addNumber(42);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "\nWay toooo many numbers...\n";
	try
	{
		Span	sp = Span(10042);
		
		sp.addManyMembersWithSpan(200, 20283, 2);
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}
