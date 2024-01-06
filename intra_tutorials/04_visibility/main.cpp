/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 17:30:43 by aulicna           #+#    #+#             */
/*   Updated: 2024/01/06 17:40:39 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Sample.class.hpp"

int main(void)
{
	Sample instance;

	instance.publicFoo = 42;
	std::cout << "instance.publicFoo: " << instance.publicFoo << std::endl;
//	instance._privateFoo = 42;
//	std::cout << "instance._privateFoo: " << instance._privateFoo << std::endl;

	instance.publicBar();
//	instance._privateBar();

	return (0);
}