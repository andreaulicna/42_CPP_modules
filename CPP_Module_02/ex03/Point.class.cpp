/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 12:16:09 by aulicna           #+#    #+#             */
/*   Updated: 2024/02/13 13:02:13 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.class.hpp"

Point::Point(void): _x(0), _y(0)
{
	std::cout << "Default constructor called." << std::endl;
}

/**
 * @brief	Float constructor that calls the Fixed class float constructor on
 * both member attributes of the Point class.
 * 
 * See also: #Fixed(const float value) in Fixed.class.cpp
*/
Point::Point(const float a, const float b): _x(a), _y(b)
{
	std::cout << "Float constructor called." << std::endl;
}

/**
 * @brief	Copy constructor for the Point class. It creates a new Point
 * instance that is a copy of an existing Point instance.
 * 
 * Example:
 * Used for initialization where Point p2(p1) will call the copy constructor,
 * which will copy the values of p1's _x and _y members
 * to p2's _x and _y members.
 * 
 * @param	copy	constant reference to a Point instance to copy
*/
Point::Point(const Point &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Point::~Point()
{
	std::cout << "Destructor called." << std::endl;
}

/** 
 * @brief	Copy assignment operator for the Point class. It assigns the value
 * of one (already existing) Point instance to another.
 * 
 * if (this != &src) checks if the current instance (this) is not the same as
 * the source instance (src). This is to prevent self-assignment, which could
 * lead to unexpected behavior.
 * 
 * this->_x = src.getX(); and this->_y = src.getY(); assign the values of src's
 * _x and _y members to the _x and _y members of the current instance. 
 * 
 * Example: 
 * Used for assignment where p1 = p2 will call the copy assignment operator,
 * which will copy the values of p2's _x and _y members
 * to p1's _x and _y members.
 * 
 * @param	src		constant reference to a Point instance
 * @return	&Point	reference to the current instance (allows for chaining
 * 					of assignment operations)
*/
Point	&Point::operator = (const Point &src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
	{
		this->_x = src.getX();
		this->_y = src.getY();
	}
	return (*this);
}

// Getters
const Fixed	&Point::getX(void) const
{
	return (*this->_x);
}

const Fixed	&Point::getY(void) const
{
	return (*this->_y);
}
