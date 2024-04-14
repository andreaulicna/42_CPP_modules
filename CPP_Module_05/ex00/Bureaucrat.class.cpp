/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.class.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 18:16:55 by aulicna           #+#    #+#             */
/*   Updated: 2024/04/14 23:24:03 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.class.hpp"

Bureaucrat::Bureaucrat(): _name("Paper clip"), _grade(150)
{
	std::cout << "Bureaucrat named '" << this->_name << "' wiht grade "<< this->_grade << " created." << std::endl;
}
		
Bureaucrat::Bureaucrat(const std::string name, int grade): _name(name)
{
	if (grade < HIGHEST_GRADE)
		throw(GradeTooHighException());
	else if (grade > LOWEST_GRADE)
		throw(GradeTooLowException());
	this->_grade = grade;
	std::cout << "Bureaucrat named '" << this->_name << "' wiht grade "<< this->_grade << " created." << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name): _name(name), _grade(150)
{
	std::cout << "Bureaucrat named '" << this->_name << "' wiht grade "<< this->_grade << " created." << std::endl;
}

Bureaucrat::Bureaucrat(int grade): _name("Paper clip")
{
	if (grade < HIGHEST_GRADE)
		throw(GradeTooHighException());
	else if (grade > LOWEST_GRADE)
		throw(GradeTooLowException());
	this->_grade = grade;
	std::cout << "Bureaucrat named '" << this->_name << "' wiht grade "<< this->_grade << " created." << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy): _name(copy.getName()), _grade(copy.getGrade())
{
	std::cout << "Bureaucrat named '" << this->_name << "' wiht grade "<< this->_grade << " copied." << std::endl;
}

// cannot assign name because it is set to const
Bureaucrat	&Bureaucrat::operator = (const Bureaucrat &src)
{
	if (this != &src)
		_grade = src._grade;
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat named '" << this->_name << "' wiht grade "<< this->_grade << " destroyed." << std::endl;
}

const std::string	&Bureaucrat::getName() const
{
	return (this->_name);
}

int	Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void	Bureaucrat::increment()
{
	if (_grade - 1 < HIGHEST_GRADE)
		throw (GradeTooHighException());
	this->_grade -= 1;
}

void	Bureaucrat::increment(int value)
{
	if (_grade - value < HIGHEST_GRADE)
		throw (GradeTooHighException());
	this->_grade -= value;
}

void	Bureaucrat::decrement()
{
	if (_grade + 1 > LOWEST_GRADE)
		throw (GradeTooLowException());
	this->_grade += 1;
}

void	Bureaucrat::decrement(int value)
{
	if (_grade + value > LOWEST_GRADE)
		throw (GradeTooLowException());
	this->_grade += value;
}

Bureaucrat	&Bureaucrat::operator ++ (void)
{
	if (_grade - 1 < HIGHEST_GRADE)
		throw (GradeTooHighException());
	this->_grade -= 1;
	return (*this);
}

Bureaucrat	Bureaucrat::operator ++ (int)
{
	if (_grade - 1 < HIGHEST_GRADE)
		throw (GradeTooHighException());
	Bureaucrat	original(*this);
	this->_grade -= 1;
	return (original);
}

Bureaucrat	&Bureaucrat::operator -- (void)
{
	if (_grade + 1 > LOWEST_GRADE)
		throw (GradeTooLowException());
	this->_grade += 1;
	return (*this);
}

Bureaucrat	Bureaucrat::operator -- (int)
{
	if (_grade + 1 > LOWEST_GRADE)
		throw (GradeTooLowException());
	Bureaucrat	original(*this);
	this->_grade += 1;
	return (original);
}

Bureaucrat::GradeTooLowException::GradeTooLowException() :
	std::invalid_argument("Grade is too low.")
{
	return ;
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low.");
}

Bureaucrat::GradeTooHighException::GradeTooHighException() :
	std::invalid_argument("Grade is too high.")
{
	return ;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high.");
}

std::ostream& operator<<(std::ostream &o, const Bureaucrat &instance)
{
	o << "Bureaucrat '" << instance.getName() << "' with grade " << instance.getGrade() << ".";
	return (o);
}