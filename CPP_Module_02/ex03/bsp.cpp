/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:05:44 by aulicna           #+#    #+#             */
/*   Updated: 2024/02/13 15:11:17 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.class.hpp"

int	calculateArea(int x1, int y1, int x2, int y2, int x3, int y3)
{
	Fixed	area;

	area = abs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2) / 2);
	//area = ((a.getX() * (b.getY() - c.getY())) + (b.getX() * (c.getY() - a.getY())) + (c.getX() * (a.getY() - b.getY())));
	return (area.toInt());
}

bool	bsp(const Point a, const Point b, const Point c, const Point point)
{
//	Fixed	area;
//	Fixed	area1;
//	Fixed	area2;
//	Fixed	area3;

	int	area;
	int	area1;
	int	area2;
	int	area3;

	// ABC
	area = calculateArea(a.getX().toInt(), a.getY().toInt(),  b.getX().toInt(), b.getY().toInt(), c.getX().toInt(), c.getY().toInt());
	// PAB
	area1 = calculateArea(point.getX().toInt(), point.getY().toInt(), a.getX().toInt(), a.getY().toInt(), b.getX().toInt(), b.getY().toInt());
	// PBC
	area1 = calculateArea(point.getX().toInt(), point.getY().toInt(), b.getX().toInt(), b.getY().toInt(), c.getX().toInt(), c.getY().toInt());
	// PAC
	area1 = calculateArea(point.getX().toInt(), point.getY().toInt(), a.getX().toInt(), a.getY().toInt(), c.getX().toInt(), c.getY().toInt());

//	if (abs(area1.toFloat() / 2) + abs(area2.toFloat() / 2) + abs(area3.toFloat() / 2) == abs(area.toFloat() / 2))
//		return (true);
	if (area1 + area2 + area3 == area)
		return (true);
	return (false);
}
