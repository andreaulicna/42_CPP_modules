/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 08:51:44 by aulicna           #+#    #+#             */
/*   Updated: 2024/04/15 12:21:10 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.class.hpp"

Form::Form(void): _name("Default"), _isSigned(false), _gradeSign(1), _gradeExec(1)
{
	std::cout << "Default form created." << std::endl;
}

Form::Form(const std::string name, int gradeSign, int gradeExec):
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

Form::Form(const Form& copy): _name(copy.getName()),
	_isSigned(copy.getIsSigned()), _gradeSign(copy.getGradeSign()),
	_gradeExec(copy.getGradeExec())
{
	std::cout << "Copying a form..." << std::endl;
	*this = copy;
}

// cannot assign name, gradeSign nor gradeExec because they're set to const
// assigning isSigned doesn't really make sense
Form	&Form::operator = (const Form &src)
{
	(void) src;
	return (*this);
}

Form::~Form(void)
{
	std::cout << "Form deleted." << std::endl;
}

const std::string	&Form::getName() const
{
	return (this->_name);
}

bool	Form::getIsSigned() const
{
	return (this->_isSigned);
}

const int	&Form::getGradeSign() const
{
	return (this->_gradeSign);
}

const int			&Form::getGradeExec() const
{
	return (this->_gradeExec);
}

void	Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_gradeSign)
		throw(GradeTooLowException());
	this->_isSigned = true;
}

Form::GradeTooLowException::GradeTooLowException() :
	std::invalid_argument("Grade is too low.")
{
	return ;
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("grade too low.");
}

Form::GradeTooHighException::GradeTooHighException() :
	std::invalid_argument("Grade is too high.")
{
	return ;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("grade too high.");
}

std::ostream	&operator<<(std::ostream &o, const Form &instance)
{
	std::cout << "Form '" << instance.getName() << "' "
		<< "[signed: " << instance.getIsSigned()
		<< ", grade to sign: " << instance.getGradeSign()
		<< ", grade to execute: " << instance.getGradeExec() << "]";
	return (o);
}
