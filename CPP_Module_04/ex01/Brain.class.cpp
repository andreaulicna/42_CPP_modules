/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 13:26:57 by aulicna           #+#    #+#             */
/*   Updated: 2024/03/26 13:54:49 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.class.hpp"

Brain::Brain(void)
{
	std::cout << "Default constructor of the Brain class called." << std::endl;
}

Brain::Brain(const Brain& copy)
{
	std::cout << "Copy constructor of the Brain class called." << std::endl;
	*this = copy;
}

Brain	&Brain::operator = (const Brain &src)
{
	std::cout << "Copy assignment operator of the Brain class called."
		<< std::endl;
	if (this != &src)
	{
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = src._ideas[i];
	}
	return (*this);
}

Brain::~Brain(void)
{
	std::cout << "Destructor of the Brain class called." << std::endl;
}
