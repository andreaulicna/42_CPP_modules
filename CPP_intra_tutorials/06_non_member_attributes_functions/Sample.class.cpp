/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 12:52:53 by aulicna           #+#    #+#             */
/*   Updated: 2024/01/07 13:12:48 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Sample.class.hpp"

Sample::Sample(void)
{
	std::cout << "Constructor called" << std::endl;
	Sample::_nbInst += 1;
	return ;
}

Sample::~Sample(void)
{
	std::cout << "Destructor callled" << std::endl;
	Sample::_nbInst -= 1;
	return ;
}

int	Sample::getNbInst(void)
{
	return (Sample::_nbInst);
}

int	Sample::_nbInst = 0;