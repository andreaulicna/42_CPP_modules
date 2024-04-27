/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.class.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 11:03:01 by aulicna           #+#    #+#             */
/*   Updated: 2024/04/27 14:37:16 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.class.hpp"

PmergeMe::PmergeMe(void)
{
	return ;
}

PmergeMe::PmergeMe(const PmergeMe& copy)
{
	this->_list = copy._list;
	this->_orderedList = copy._list;
	this->_vector = copy._vector;
	this->_orderedVector = copy._orderedVector;
}

PmergeMe	&PmergeMe::operator = (const PmergeMe &src)
{
	if(this != &src)
	{
		this->_list = src._list;
		this->_orderedList = src._list;
		this->_vector = src._vector;
		this->_orderedVector = src._orderedVector;
	}
	return (*this);
}

PmergeMe::~PmergeMe(void)
{
	return ;
}

template <typename T>
void	printContainer(const T &container, const std::string containerName)
{
	std::cout << containerName << " ";
	for (typename T::const_iterator it = container.begin(); it != container.end(); ++it)
		std::cout << *it << ' ';
	std::cout << std::endl;
}

PmergeMe::PmergeMe(int argc, char **argv)
{
//	// Input validation
//	if (input.find_first_not_of("0123456789 ") != std::string::npos)
//		throw(std::invalid_argument("Invalid characters provided on the input."));
	
	// Reserve space for vector 
	this->_vector.reserve(argc - 1);	
	this->_orderedVector.reserve(argc - 1);

	// Fill containers
	for (int i = 1; i < argc; i++)
		this->_list.push_back(std::atoi(argv[i]));
	for (int i = 1; i < argc; i++)
		this->_vector.push_back(std::atoi(argv[i]));
	
	for(std::vector<unsigned int>::iterator it = this->_vector.begin(); it != this->_vector.end(); ++it)
		std::cout << *it << ' ';
	std::cout << std::endl;
	std::cout << "Overload: " << this->_vector << std::endl;
}

std::ostream	&operator << (std::ostream &o, vect_uint_t &vector)
{
	for(vect_uint_t::iterator it = vector.begin(); it != vector.end(); ++it)
		o << *it << ' ';
	return (o);
}