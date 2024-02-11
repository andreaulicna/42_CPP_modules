/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 11:57:32 by aulicna           #+#    #+#             */
/*   Updated: 2024/02/11 11:03:04 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.class.hpp"

int main(void)
{
	Fixed a;
	Fixed const b( Fixed(5.05f) * Fixed(2));

	std::cout << a << std::endl;
//	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
//	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
//	std::cout << Fixed::max(a, b) << std::endl;
	return (0);
}
