/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 13:26:57 by aulicna           #+#    #+#             */
/*   Updated: 2024/03/26 15:27:13aulicna          ###   ########.fr       */
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
		{
			if (src._ideas[i].length() > 0)
				this->_ideas[i] = src._ideas[i];
		}
	}
	return (*this);
}

Brain::~Brain(void)
{
	std::cout << "Destructor of the Brain class called." << std::endl;
}

const std::string	Brain::getIdea(int i) const
{
	if (i < 100)
		return (this->_ideas[i]);
	else
		return ("The brain's capacity is 100 ideas only.");
}

const std::string	*Brain::getIdeaAddress(int i) const
{
	if (i < 100)
		return (&(this->_ideas[i]));
	return (NULL);
}

void	Brain::setIdea(std::string idea, int i)
{
	if (i < 100)
		this->_ideas[i] = idea;
	else
		std::cerr << "Sorry, the brain doesn't have the capacity for such a big idea." << std::endl;
}
