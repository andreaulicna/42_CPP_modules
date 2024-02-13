/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:05:44 by aulicna           #+#    #+#             */
/*   Updated: 2024/02/13 16:09:44 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.class.hpp"

Fixed	calculateArea(int x1, int y1, int x2, int y2, int x3, int y3)
{
	float	area;

	area = fabs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0);
	//area = ((a.getX() * (b.getY() - c.getY())) + (b.getX() * (c.getY() - a.getY())) + (c.getX() * (a.getY() - b.getY())));
	return (Fixed(area));
}

bool	bsp(const Point a, const Point b, const Point c, const Point point)
{
	Fixed	area;
	Fixed	area1;
	Fixed	area2;
	Fixed	area3;

	// ABC
	area = calculateArea(a.getX().toInt(), a.getY().toInt(),  b.getX().toInt(), b.getY().toInt(), c.getX().toInt(), c.getY().toInt());
	// PAB
	area1 = calculateArea(point.getX().toInt(), point.getY().toInt(), a.getX().toInt(), a.getY().toInt(), b.getX().toInt(), b.getY().toInt());
	// PBC
	area2 = calculateArea(point.getX().toInt(), point.getY().toInt(), b.getX().toInt(), b.getY().toInt(), c.getX().toInt(), c.getY().toInt());
	// PAC
	area3 = calculateArea(point.getX().toInt(), point.getY().toInt(), a.getX().toInt(), a.getY().toInt(), c.getX().toInt(), c.getY().toInt());

	return (area1 + area2 + area3 == area);
}
