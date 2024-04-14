/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 18:19:45 by aulicna           #+#    #+#             */
/*   Updated: 2024/04/14 23:35:08 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.class.hpp"

int	main(void)
{
	try
	{
		Bureaucrat	pen("Pen", 1);
		std::cout << pen << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Bureaucrat	pen("Pen", 160);
		std::cout << pen << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Bureaucrat	pen("Pen", -1);
		std::cout << pen << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	Bureaucrat	pencil("Pencil", 150);
	try
	{
		pencil.decrement();
		pencil.increment();
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		pencil.increment();
		std::cout << pencil << std::endl;
		pencil.decrement();
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		pencil.increment(1000);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::cout << pencil << std::endl;
		for (int i = 0; i < 30; i++)
			++pencil;
		std::cout << pencil << std::endl;
		for (int i = 0; i < 30; i++)
			--pencil;
		std::cout << pencil << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::cout << pencil++ << std::endl;
		std::cout << pencil-- << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}