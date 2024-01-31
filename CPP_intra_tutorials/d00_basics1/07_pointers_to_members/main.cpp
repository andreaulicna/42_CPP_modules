/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 13:17:30 by aulicna           #+#    #+#             */
/*   Updated: 2024/01/31 14:37:13 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Sample.class.hpp"

int	main(void)
{
	Sample	instance;
	Sample	*instancep = &instance;

	// syntax of a pointer on a member attribute (int type) of the Sample class
	int		Sample::*p = NULL;
	// pointer on a member function of the Sample class
	void	(Sample::*f)(void) const;

	// assign the address of foo to pointer p, but not for a specific instance
	p = &Sample::foo;

	std::cout << "Value of member foo: " << instance.foo << std::endl;
	instance.*p = 21; // use .* operator on an instance to get its specific foo
	std::cout << "Value of member foo: " << instance.foo << std::endl;
	instancep->*p = 42;
	std::cout << "Value of member foo: " << instance.foo << std::endl;

	// assign the address of bar to pointer f, but not for a specific instance
	f = &Sample::bar;

	(instance.*f)();
	(instancep->*f)();

	return (0);
}