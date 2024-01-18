/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:55:03 by aulicna           #+#    #+#             */
/*   Updated: 2024/01/18 18:21:31 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

/**
 * The memory address held by stringPTR: stringPTR is a pointer that holds
 * the memory address of the str variable, so it should be printed as-is. If
 * we were to print &stringPTR, it would print the memory address
 * of the stringPTR variable itself, not the memory address it is holding.
 * 
 * The memory address held by stringREF: A reference is just another name
 * for an existing variable, so it doesn't have its own memory address. 
 * Printing &stringREF gives the memory address of str which is the memory
 * address referred to by stringREF.
*/
int main(void)
{
	std::string	str = "HI THIS IS BRAIN";
	std::string	*stringPTR = &str;
	std::string	&stringREF = str;

	std::cout << "The memory address of the string variable: " << &str << '\n';
	std::cout << "The memory address held by stringPTR: " << stringPTR << '\n';
	std::cout << "The memory address held by stringREF: " << &stringREF << '\n';
	std::cout << "The value of the string variable: " << str << '\n';
	std::cout << "The value pointed to by stringPTR: " << *stringPTR << '\n';
	std::cout << "The value pointed to by stringREF: " << stringREF
		<< std::endl;
	return (0);	
}
