/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 11:57:32 by aulicna           #+#    #+#             */
/*   Updated: 2024/02/12 17:46:20 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.class.hpp"

int main(void)
{
	Fixed	a;
	Fixed	b(Fixed(5.05f) * Fixed(2));
	Fixed	c;
	Fixed	const d(Fixed(5.05f) * Fixed(2));
	Fixed	num1(Fixed(1.2f));
	Fixed	num2(Fixed(42));
	Fixed	num3(Fixed(42));
	Fixed	num4(Fixed(43));

	std::cout << "Comparison operators overloads:\n";
	std::cout << "num1 = " << num1 << "\n";
	std::cout << "num2 = " << num2 << "\n";
	std::cout << "num3 = " << num3 << "\n";
	std::cout << "num4 = " << num4 << "\n";
	std::cout << "num1 > num2: " << (num1 > num2) << "\n"; 
	std::cout << "num1 < num2: " << (num1 < num2) << "\n"; 
	std::cout << "num3 >= num2: " << (num3 >= num2) << "\n"; 
	std::cout << "num3 <= num4: " << (num3 <= num4) << "\n"; 
	std::cout << "num3 != num2: " << (num3 != num2) << "\n"; 

	std::cout << "\nArithmetic operators: \n";
	std::cout << "num2 + num3: " << num2 + num3 << "\n";
	std::cout << "num4 - num3: " << num4 - num3 << "\n";
	std::cout << "num1 * num2: " << num1 * num2 << "\n";
	std::cout << "num4 / num3: " << num4 / num3 << "\n";
	

	std::cout << "\nPre and post-increment operators: \n";
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;

	std::cout << "\nPre and post-decrement operators: \n";
	std::cout << c << std::endl;
	std::cout << --c << std::endl;
	std::cout << c << std::endl;
	std::cout << c-- << std::endl;
	std::cout << c << std::endl;

	std::cout << "\nMax and min: \n";
	std::cout << "a = " << a << "\n";
	std::cout << "b = " << b << "\n";
	std::cout << "max = " << Fixed::max(a, b) << std::endl;
	std::cout << "min = " << Fixed::min(a, b) << std::endl;

	std::cout << "\nMax and min (const): \n";
	std::cout << "a = " << a << "\n";
	std::cout << "d = " << d << "\n";
	std::cout << "max = " << Fixed::max(a, d) << std::endl;
	std::cout << "min = " << Fixed::min(a, d) << std::endl;

	// Attempt to modify a const returned object that throws a compiler error
//	const Fixed &e = Fixed::max(a, d);
//	std::cout << "e = " << e << "\n";
//	e++;
//	e = Fixed(7.7f);
	return (0);
}
