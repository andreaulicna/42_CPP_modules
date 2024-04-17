/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.class.cpp                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:49:03 by aulicna           #+#    #+#             */
/*   Updated: 2024/04/17 19:30:49 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.class.hpp"

RobotomyRequestForm::RobotomyRequestForm(void):
	AForm("Robotomy Request", 72, 45), _target("Anonymous")
{
//	std::cout << "Robotomy Request form created." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target):
	AForm("Robotomy Request", 72, 45), _target(target)
{
//	std::cout << "Robotomy Request form created." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy):
	AForm("Robotomy Request", 72, 45)
{
	this->_target = copy._target;
	std::cout << "Copying Robotomy Request form..." << std::endl;
	*this = copy;
}

RobotomyRequestForm	&RobotomyRequestForm::operator = (const RobotomyRequestForm &src)
{
	if (this != &src)
		this->_target = src._target;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
//	std::cout << "Robotomy Request form destroyed." << std::endl;
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor)
{
	AForm::checkIfExecutable(executor);
	std::cout << "Making some driling noises... ";
	srand(time(0));
	if (rand() % 2)
		std::cout << "Informing that '" << this->_target
			<< "' has been successfully robotomized." << std::endl;
	else
		std::cout << "Informing that '" << this->_target
			<< "' has NOT been successfully robotomized." << std::endl;
}