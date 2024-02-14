/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:05:44 by aulicna           #+#    #+#             */
/*   Updated: 2024/02/14 12:27:17 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.class.hpp"

/**
 * @brief Calculates the area of a triangle defined by three points.
 * 
 * This function uses the formula for the area of a triangle based on its
 * points coordinates. The area is calculated as the absolute value
 * of the result to ensure it's always positive.
 * 
 * @param	p1		first point of the triangle
 * @param	p2		second point of the triangle
 * @param	p3		third point of the triangle
 * @return	Fixed	returns the area of the triangle
 */
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

/**
 * @brief Checks if a point is inside a triangle.
 * 
 * This function uses the Barycentric coordinate system to determine if
 * a point is inside a triangle. It calculates the area of the triangle and
 * the areas of three triangles formed by the point and each pair of triangle
 * points. If the sum of the three smaller areas equals the area
 * of the original triangle, the point is inside the triangle.
 * 
 * @param	a		first point of the triangle
 * @param	b		second point of the triangle
 * @param	c		third point of the triangle
 * @param	point	point to check
 * @return	bool	returns true if the point is inside the triangle,
 * 					false otherwise
 */
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
