/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.class.cpp                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:49:03 by aulicna           #+#    #+#             */
/*   Updated: 2024/04/17 19:30:38 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.class.hpp"

PresidentialPardonForm::PresidentialPardonForm(void):
	AForm("Presidential Pardon", 25, 5), _target("Anonymous")
{
//	std::cout << "Presidential Pardon form created." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target):
	AForm("Presidential Pardon", 25, 5), _target(target)
{
//	std::cout << "Presidential Pardon form created." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy):
	AForm("Presidential Pardon", 25, 5)
{
	this->_target = copy._target;
	std::cout << "Copying Presidential Pardon form..." << std::endl;
	*this = copy;
}

PresidentialPardonForm	&PresidentialPardonForm::operator = (const PresidentialPardonForm &src)
{
	if (this != &src)
		this->_target = src._target;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
//	std::cout << "Presidential Pardon form destroyed." << std::endl;
}

void	PresidentialPardonForm::execute(Bureaucrat const &executor)
{
	AForm::checkIfExecutable(executor);
	std::cout << "FYI, '" << this->_target
		<< "' has been pardoned by Zaphod Beeblebrox." << std::endl;
}