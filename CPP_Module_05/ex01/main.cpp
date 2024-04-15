/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 18:19:45 by aulicna           #+#    #+#             */
/*   Updated: 2024/04/15 12:19:04 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.class.hpp"
#include "Form.class.hpp"

int	main(void)
{
	std::cout << "CREATE FORM RIGHT" << std::endl;
	try
	{
		Form	app("app", 2, 3);
		Form	ballot;

		std::cout << app << std::endl;
		std::cout << ballot << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "\nCREATE FORM WRONG" << std::endl;
	try
	{
		Form	ballot("ballot", 160, 150);

		std::cout << ballot << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "\nSIGN FORM RIGHT" << std::endl;
	try
	{
		Bureaucrat	employee(60);
		Form		app("Application", 100, 80);
		
		std::cout << employee << std::endl;
		std::cout << app << std::endl;
		employee.signForm(app);
		std::cout << app << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "\nSIGN FORM WRONG" << std::endl;
	try
	{
		Bureaucrat	employee;
		Form		app("Application", 100, 80);
		
		std::cout << employee << std::endl;
		std::cout << app << std::endl;
		employee.signForm(app);
		std::cout << app << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "\nSIGN FORM TWICE" << std::endl;
	try
	{
		Bureaucrat	employee(60);
		Form		app("Application", 100, 80);
		
		std::cout << employee << std::endl;
		std::cout << app << std::endl;
		employee.signForm(app);
		std::cout << app << std::endl;
		employee.signForm(app);
		std::cout << app << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
//	EX00
//	try
//	{
//		Bureaucrat	pen("Pen", 1);
//		std::cout << pen << std::endl;
//	}
//	catch (const std::exception &e)
//	{
//		std::cerr << e.what() << std::endl;
//	}
//	try
//	{
//		Bureaucrat	pen("Pen", 160);
//		std::cout << pen << std::endl;
//	}
//	catch (const std::exception &e)
//	{
//		std::cerr << e.what() << std::endl;
//	}
//	try
//	{
//		Bureaucrat	pen("Pen", -1);
//		std::cout << pen << std::endl;
//	}
//	catch (const std::exception &e)
//	{
//		std::cerr << e.what() << std::endl;
//	}
//
//	Bureaucrat	pencil("Pencil", 150);
//	try
//	{
//		pencil.decrement();
//		pencil.increment();
//	}
//	catch (const std::exception &e)
//	{
//		std::cerr << e.what() << std::endl;
//	}
//	try
//	{
//		pencil.increment();
//		std::cout << pencil << std::endl;
//		pencil.decrement();
//	}
//	catch (const std::exception &e)
//	{
//		std::cerr << e.what() << std::endl;
//	}
//	try
//	{
//		pencil.increment(1000);
//	}
//	catch (const std::exception &e)
//	{
//		std::cerr << e.what() << std::endl;
//	}
//	try
//	{
//		std::cout << pencil << std::endl;
//		for (int i = 0; i < 30; i++)
//			++pencil;
//		std::cout << pencil << std::endl;
//		for (int i = 0; i < 30; i++)
//			--pencil;
//		std::cout << pencil << std::endl;
//	}
//	catch (const std::exception &e)
//	{
//		std::cerr << e.what() << std::endl;
//	}
//	try
//	{
//		std::cout << pencil++ << std::endl;
//		std::cout << pencil-- << std::endl;
//	}
//	catch (const std::exception &e)
//	{
//		std::cerr << e.what() << std::endl;
//	}
	return (0);
}