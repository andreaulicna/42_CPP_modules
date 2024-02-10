/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Integer.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 14:54:10 by aulicna           #+#    #+#             */
/*   Updated: 2024/02/10 15:17:32 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Integer.class.hpp"

Integer::Integer(int const n): _n(n)
{
	std::cout << "Constructor called with: " << this->_n << std::endl;
}

Integer::~Integer(void)
{
	std::cout << "Destructor called with: " << this->_n << std::endl;
}

int	Integer::getValue(void) const
{
	return (this->_n);
}

Integer	&Integer::operator=(Integer const &rhs)
{
	std::cout << "Assignation operator called from " << this->_n;
	std::cout << " to " << rhs.getValue() << std::endl;
	this->_n = rhs.getValue();
	return (*this);
}

Integer	Integer::operator+(Integer const &rhs) const
{
	std::cout << "Addition operator called from " << this->_n;
	std::cout << " and " << rhs.getValue() << std::endl;
	return (Integer(this->_n + rhs.getValue()));
}

std::ostream	&operator<<(std::ostream &o, Integer const &rhs)
{
	o << rhs.getValue();
	return (o);
}