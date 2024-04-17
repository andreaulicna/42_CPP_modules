/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 18:19:45 by aulicna           #+#    #+#             */
/*   Updated: 2024/04/17 20:17:49 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.class.hpp"
#include "Intern.class.hpp"
#include "AForm.class.hpp"
#include "PresidentialPardonForm.class.hpp"
#include "RobotomyRequestForm.class.hpp"
#include "ShrubberyCreationForm.class.hpp"

int	main(void)
{
	Bureaucrat	*employee = new Bureaucrat("Jack", 1);
	Bureaucrat	*employee2 = new Bureaucrat("Joe", 60);
	Intern		*intern = new Intern();
	AForm		*pardon = intern->makeForm("PresidentialPardonForm", "A");
	AForm		*robotomy = intern->makeForm("RobotomyRequestForm", "B");
	AForm		*shrubbery = intern->makeForm("ShrubberyCreationForm", "C");
	AForm		*test = intern->makeForm("NoName", "D");

	std::cout << employee << "\n";
	std::cout << pardon << "\n";
	std::cout << robotomy << "\n";
	std::cout << shrubbery << "\n";
	std::cout << test << std::endl;

	try
	{
		employee2->signForm(*shrubbery);
		employee2->executeForm(*shrubbery);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		employee2->signForm(*robotomy);
		employee2->executeForm(*robotomy);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		employee2->signForm(*robotomy);
		employee->executeForm(*robotomy);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	delete employee;
	delete employee2;
	delete intern;
	delete pardon;
	delete robotomy;
	delete shrubbery;

//	std::cout << "PRESIDENTIAL FORM RIGHT" << std::endl;
//	try
//	{
//		Bureaucrat	employee("Max", 1);
//		PresidentialPardonForm	pardon("John");
//
//		std::cout << employee << std::endl;
//		std::cout << pardon << std::endl;
//		employee.signForm(pardon);
//		employee.executeForm(pardon);
//	}
//	catch (const std::exception &e)
//	{
//		std::cerr << e.what() << std::endl;
//	}
//	std::cout << std::endl;
//	std::cout << "PRESIDENTIAL FORM NOT SIGNED" << std::endl;
//	try
//	{
//		Bureaucrat	employee("Tim", 1);
//		PresidentialPardonForm	pardon;
//
//		std::cout << employee << std::endl;
//		std::cout << pardon << std::endl;
//		employee.executeForm(pardon);
//	}
//	catch (const std::exception &e)
//	{
//		std::cerr << e.what() << std::endl;
//	}
//	std::cout << std::endl;
//	std::cout << "PRESIDENTIAL FORM CANNOT SIGN" << std::endl;
//	try
//	{
//		Bureaucrat	employee;
//		PresidentialPardonForm	pardon;
//
//		std::cout << employee << std::endl;
//		std::cout << pardon << std::endl;
//		employee.signForm(pardon);
//	}
//	catch (const std::exception &e)
//	{
//		std::cerr << e.what() << std::endl;
//	}
//	std::cout << std::endl;
//	std::cout << "PRESIDENTIAL FORM CANNOT EXECUTE" << std::endl;
//	try
//	{
//		Bureaucrat	employee(20);
//		PresidentialPardonForm	pardon;
//
//		std::cout << employee << std::endl;
//		std::cout << pardon << std::endl;
//		employee.signForm(pardon);
//		employee.executeForm(pardon);
//	}
//	catch (const std::exception &e)
//	{
//		std::cerr << e.what() << std::endl;
//	}
//	
//	std::cout << std::endl;
//	std::cout << "ROBOTOMY FORM RIGHT" << std::endl;
//	try
//	{
//		Bureaucrat	employee("Max", 1);
//		RobotomyRequestForm	robotomy("John");
//
//		std::cout << employee << std::endl;
//		std::cout << robotomy << std::endl;
//		employee.signForm(robotomy);
//		employee.executeForm(robotomy);
//	}
//	catch (const std::exception &e)
//	{
//		std::cerr << e.what() << std::endl;
//	}
//	std::cout << std::endl;
//	std::cout << "ROBOTOMY FORM NOT SIGNED" << std::endl;
//	try
//	{
//		Bureaucrat	employee("Tim", 1);
//		RobotomyRequestForm	robotomy("John");
//
//		std::cout << employee << std::endl;
//		std::cout << robotomy << std::endl;
//		employee.executeForm(robotomy);
//	}
//	catch (const std::exception &e)
//	{
//		std::cerr << e.what() << std::endl;
//	}
//	std::cout << std::endl;
//	std::cout << "ROBOTOMY FORM CANNOT SIGN" << std::endl;
//	try
//	{
//		Bureaucrat	employee;
//		RobotomyRequestForm	robotomy("John");
//
//		std::cout << employee << std::endl;
//		std::cout << robotomy << std::endl;
//		employee.signForm(robotomy);
//	}
//	catch (const std::exception &e)
//	{
//		std::cerr << e.what() << std::endl;
//	}
//	std::cout << std::endl;
//	std::cout << "ROBOTOMY FORM CANNOT EXECUTE" << std::endl;
//	try
//	{
//		Bureaucrat	employee(46);
//		RobotomyRequestForm	robotomy("John");
//
//		std::cout << employee << std::endl;
//		std::cout << robotomy << std::endl;
//		employee.signForm(robotomy);
//		employee.executeForm(robotomy);
//	}
//	catch (const std::exception &e)
//	{
//		std::cerr << e.what() << std::endl;
//	}
//
//	std::cout << std::endl;
//	std::cout << "SHRUBERRY FORM RIGHT" << std::endl;
//	try
//	{
//		Bureaucrat	employee("Max", 1);
//		ShrubberyCreationForm	shrubbery("home");
//
//		std::cout << employee << std::endl;
//		std::cout << shrubbery << std::endl;
//		employee.signForm(shrubbery);
//		employee.executeForm(shrubbery);
//	}
//	catch (const std::exception &e)
//	{
//		std::cerr << e.what() << std::endl;
//	}
//	std::cout << std::endl;
//	std::cout << "SHRUBERRY FORM NOT SIGNED" << std::endl;
//	try
//	{
//		Bureaucrat	employee("Tim", 1);
//		ShrubberyCreationForm	shrubbery("home");
//
//		std::cout << employee << std::endl;
//		std::cout << shrubbery << std::endl;
//		employee.executeForm(shrubbery);
//	}
//	catch (const std::exception &e)
//	{
//		std::cerr << e.what() << std::endl;
//	}
//	std::cout << std::endl;
//	std::cout << "SHRUBERRY FORM CANNOT SIGN" << std::endl;
//	try
//	{
//		Bureaucrat	employee;
//		ShrubberyCreationForm	shrubbery("home");
//
//		std::cout << employee << std::endl;
//		std::cout << shrubbery << std::endl;
//		employee.signForm(shrubbery);
//	}
//	catch (const std::exception &e)
//	{
//		std::cerr << e.what() << std::endl;
//	}
//	std::cout << std::endl;
//	std::cout << "SHRUBERRY FORM CANNOT EXECUTE" << std::endl;
//	try
//	{
//		Bureaucrat	employee(138);
//		ShrubberyCreationForm	shrubbery("home");
//
//		std::cout << employee << std::endl;
//		std::cout << shrubbery << std::endl;
//		employee.signForm(shrubbery);
//		employee.executeForm(shrubbery);
//	}
//	catch (const std::exception &e)
//	{
//		std::cerr << e.what() << std::endl;
//	}
	return (0);
}