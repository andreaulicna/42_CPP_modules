/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 12:15:09 by aulicna           #+#    #+#             */
/*   Updated: 2024/02/13 14:30:21 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_CLASS_HPP
# define POINT_CLASS_HPP

# include <cmath>
# include <iostream>
# include "Fixed.class.hpp"

class Point
{
public:
	// Constructors
	Point(void);
	Point(const float a, const float b);
	// Copy constructor
	Point(const Point &copy);
	// Destructor
	~Point();

	// Copy assignment operator overload
	Point	&operator = (const Point &src);

	// Getters
	const Fixed	&getX(void) const;
	const Fixed	&getY(void) const;

private:
	const Fixed	_x;
	const Fixed	_y;
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif