/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 19:34:34 by aulicna           #+#    #+#             */
/*   Updated: 2024/04/17 20:05:06 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.class.hpp"

Intern::Intern(void)
{
	return ;
}

Intern::Intern(const Intern& copy)
{
	*this = copy;
}

Intern	&Intern::operator = (const Intern &src)
{
	(void)src;
	return (*this);
}

Intern::~Intern(void)
{
	return ;
}

static AForm*	newPresidentialPardonForm(const std::string target)
{
	return (new PresidentialPardonForm(target));
}

static AForm*	newRobotomyRequestForm(const std::string target)
{
	return (new RobotomyRequestForm(target));
}

static AForm*	newShrubberyCreationForm(const std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm	*Intern::makeForm(const std::string name, const std::string target)
{
	std::string	forms[] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};
	AForm	*(*allForms[])(const std::string target) = {&newPresidentialPardonForm, &newRobotomyRequestForm, &newShrubberyCreationForm};

	for (int i = 0; i < 3; i++)
	{
		if (name == forms[i])
		{
			std::cout << "Intern is creating '" << name << "' form, please be patient." << std::endl;
			return (allForms[i](target));
		}
	}
	std::cerr << "Intern cannot create a '" << name << "' form." << std::endl;
	return (NULL);
}
	