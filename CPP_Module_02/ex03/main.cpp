/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 11:57:32 by aulicna           #+#    #+#             */
/*   Updated: 2024/02/13 14:42:06 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.class.hpp"

int main(void)
{
	Point	a(0, 0);
	Point	b(10, 30);
	Point	c(20, 0);
	Point	p1(10, 15);
	Point	p2(30, 15);

	std::cout << "Is p1 is the triangle? " << bsp(a, b, c, p1) << std::endl; 
	std::cout << "Is p2 is the triangle? " << bsp(a, b, c, p2) << std::endl; 

	return (0);
}
