/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 13:14:53 by aulicna           #+#    #+#             */
/*   Updated: 2024/01/07 13:18:20 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Sample.class.hpp"

Sample::Sample(void): foo(0)
{
	std::cout << "Constructor called" << std::endl;
	return ;
}

Sample::~Sample()
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

void	Sample::bar(void) const
{
	std::cout << "Member function bar called" << std::endl;
	return ;
}
