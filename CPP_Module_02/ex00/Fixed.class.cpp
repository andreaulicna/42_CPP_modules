/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 12:30:12 by aulicna           #+#    #+#             */
/*   Updated: 2024/02/10 20:32:15 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.class.hpp"

const int	Fixed::_FRACTIONAL_BITS = 8;

Fixed::Fixed(void): _fixPointNumber(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

/** 
 * @brief	Copy assignment operator for the Fixed class. It assigns the value
 * of one Fixed instance to another.
 * 
 * if (this != &src) checks if the current instance (this) is not the same as
 * the source instance (src). This is to prevent self-assignment, which could
 * lead to unexpected behavior.
 * 
 * this->_fixPointNumber = src.getRawBits(); assigns the value of src's
 * _fixPointNumber member to the _fixPointNumber member of the current instance. 
 * 
 * Example: 
 * Used for assignment where f1 = f2 will call the copy assignment operator,
 * which will copy the value of f2's _fixPointNumber member
 * to f1's _fixPointNumber member.
 * 
 * @param	src		constant reference to a Fixed instance
 * @return	&Fixed	reference to the current instance (allow for chaining
 * 					of assignment operations)
*/
Fixed &Fixed::operator=(const Fixed &src)
Fixed &Fixed::operator=(const Fixed &src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
		this->_fixPointNumber = src.getRawBits();
	return *this;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixPointNumber);
}

void	Fixed::setRawBits(int const raw)
{
	this->_fixPointNumber = raw;
}