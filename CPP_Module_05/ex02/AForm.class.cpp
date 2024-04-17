/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 08:51:44 by aulicna           #+#    #+#             */
/*   Updated: 2024/04/17 14:35:23 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.class.hpp"

AForm::AForm(void): _name("Default"), _isSigned(false), _gradeSign(1), _gradeExec(1)
{
	std::cout << "Default form created." << std::endl;
}

AForm::AForm(const std::string name, int gradeSign, int gradeExec):
	_name(name), _isSigned(false), _gradeSign(gradeSign), _gradeExec(gradeExec)
{
	if (gradeSign < HIGHEST_GRADE)
		throw(GradeTooHighException());
	else if (gradeSign > LOWEST_GRADE)
		throw(GradeTooLowException());
	else if (gradeExec < HIGHEST_GRADE)
		throw(GradeTooHighException());
	else if (gradeExec > LOWEST_GRADE)
		throw(GradeTooLowException());
	std::cout << "Special form created." << std::endl;
}

AForm::AForm(const AForm& copy): _name(copy.getName()),
	_isSigned(copy.getIsSigned()), _gradeSign(copy.getGradeSign()),
	_gradeExec(copy.getGradeExec())
{
	std::cout << "Copying a form..." << std::endl;
	*this = copy;
}

// cannot assign name, gradeSign nor gradeExec because they're set to const
// assigning isSigned doesn't really make sense
AForm	&AForm::operator = (const AForm &src)
{
	(void) src;
	return (*this);
}

AForm::~AForm(void)
{
	std::cout << "AForm ." << std::endl;
}

const std::string	&AForm::getName() const
{
	return (this->_name);
}

bool	AForm::getIsSigned() const
{
	return (this->_isSigned);
}

const int	&AForm::getGradeSign() const
{
	return (this->_gradeSign);
}

const int			&AForm::getGradeExec() const
{
	return (this->_gradeExec);
}

void	AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_gradeSign)
		throw(GradeTooLowException());
	this->_isSigned = true;
}

void	AForm::checkIfExecutable(Bureaucrat const &executor) const
{
	if (this->_isSigned == false)
		throw(FormNotSignedException());
	else if (this->getGradeExec() < executor.getGrade())
		throw(GradeTooLowException());
}

AForm::GradeTooLowException::GradeTooLowException() :
	std::invalid_argument("Grade is too low.")
{
	return ;
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("grade too low.");
}

AForm::GradeTooHighException::GradeTooHighException() :
	std::invalid_argument("Grade is too high.")
{
	return ;
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("grade too high.");
}

AForm::FormNotSignedException::FormNotSignedException() :
	std::invalid_argument("Form hasn't been signed yet.")
{
	return ;
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return ("form not signed yet.");
}

std::ostream	&operator<<(std::ostream &o, const AForm &instance)
{
	std::cout << "AForm '" << instance.getName() << "' "
		<< "[signed: " << instance.getIsSigned()
		<< ", grade to sign: " << instance.getGradeSign()
		<< ", grade to execute: " << instance.getGradeExec() << "]";
	return (o);
}
