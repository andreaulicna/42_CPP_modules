/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:05:44 by aulicna           #+#    #+#             */
/*   Updated: 2024/02/13 16:37:53 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.class.hpp"

Fixed	calculateArea(const Point p1, const Point p2, const Point p3)
{
	Fixed	area;
	Fixed	areaFormula;

	areaFormula = (p1.getX() * (p2.getY() - p3.getY())
		+ p2.getX() * (p3.getY() - p1.getY())
		+ p3.getX() * (p1.getY() - p2.getY()))
		/ 2.0f;
	area = abs(areaFormula.toInt());
	return (area);
}

bool	bsp(const Point a, const Point b, const Point c, const Point point)
{
	Fixed	area;
	Fixed	area1;
	Fixed	area2;
	Fixed	area3;

	area = calculateArea(a, b, c);
	area1 = calculateArea(point, a, b);
	area2 = calculateArea(point, b, c);
	area3 = calculateArea(point, a, c);
	return (area1 + area2 + area3 == area);
}
