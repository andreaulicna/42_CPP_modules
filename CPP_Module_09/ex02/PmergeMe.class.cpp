/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.class.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 11:03:01 by aulicna           #+#    #+#             */
/*   Updated: 2024/04/27 18:21:02 by aulicna          ###   ########.fr       */
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
	this->_sortedList = copy._list;
	this->_vector = copy._vector;
	this->_sortedVector = copy._sortedVector;
}

PmergeMe	&PmergeMe::operator = (const PmergeMe &src)
{
	if(this != &src)
	{
		this->_list = src._list;
		this->_sortedList = src._list;
		this->_vector = src._vector;
		this->_sortedVector = src._sortedVector;
	}
	return (*this);
}

PmergeMe::~PmergeMe(void)
{
	return ;
}


unsigned int	PmergeMe::_jacobsthalNumber(unsigned int iJacobsthal)
{
	if (iJacobsthal == 0 || iJacobsthal == 1)
		return (iJacobsthal);
	return (_jacobsthalNumber(iJacobsthal - 1) + 2 * _jacobsthalNumber(iJacobsthal - 2));

}

void PmergeMe::_insertIntoList(std::list< std::pair<unsigned int, unsigned int> > pairsList,
							   std::list<unsigned int> insertionSequence, bool odd, unsigned int struggler)
{
	std::list< std::pair<unsigned int, unsigned int> >::iterator itPairsList;
	std::list<unsigned int>::iterator itSortedList;
	unsigned int indexNumToInsert;

	for(std::list<unsigned int>::iterator it = insertionSequence.begin(); it != insertionSequence.end(); ++it)
	{
		indexNumToInsert = *it;
		if (indexNumToInsert < pairsList.size())
		{
			itPairsList = pairsList.begin();
			std::advance(itPairsList, indexNumToInsert);
			itSortedList = std::upper_bound(_sortedList.begin(), _sortedList.end(), itPairsList->second);
			_sortedList.insert(itSortedList, itPairsList->second);
			std::cout << "Inserting " << itPairsList->second << std::endl;
		}
		else
			std::cout << "Skipped non-existent index." << std::endl;
		std::cout << "Main chain update: " << _sortedList << std::endl;
	}
	if (odd)
	{
		itSortedList = std::upper_bound(_sortedList.begin(), _sortedList.end(), struggler);
		_sortedList.insert(itSortedList, struggler);
	}

}

void	PmergeMe::_sort(std::list<unsigned int> &list)
{
	bool												odd;
	unsigned int										struggler;
	std::list< std::pair<unsigned int, unsigned int> >	pairsList;
	unsigned int										first;
	unsigned int										second;
	std::list<unsigned int>								insertionSequence;

	// Check for odd sequence and save struggler if so
	odd = false;
	if (list.size() % 2 == 1)
	{
		odd = true;
		struggler = list.back();
		list.pop_back();
	}
	// Make pairs and put the larger number of within the pair as the first one
	for(std::list<unsigned int>::iterator it = list.begin(); it != list.end(); it++)
	{
		first = *it;
		it++;
		if (it != list.end())
		{
			second = *it;
			if (first < second)
				pairsList.push_back(std::make_pair(second, first));
			else
				pairsList.push_back(std::make_pair(first, second));
		}
	}
	std::cout << "List of pairs: " << pairsList << std::endl;
	if (odd)
		std::cout << "Struggler: " << struggler << std::endl;
	// Sort pairs
	pairsList.sort(compare());
	std::cout << "List of sorted pairs: " << pairsList << std::endl;
	if (odd)
		std::cout << "Struggler: " << struggler << std::endl;
	// Main chain and pend
	for(std::list< std::pair<unsigned int, unsigned int> >::iterator it = pairsList.begin(); it != pairsList.end(); ++it)
		this->_sortedList.push_back(it->first);
	std::cout << "Main chain: " << this->_sortedList << std::endl;
	// First element of pend to the main chain
	this->_sortedList.push_front(pairsList.begin()->second);
	std::cout << "Main chain with b1: " << this->_sortedList << std::endl;
	insertionSequence = _generateJacobsthalSequence<std::list <unsigned int> >(pairsList.size());
	// Jacob and insertion sequences
	std::cout << "Jacob sequence: " << insertionSequence << std::endl;
	insertionSequence = _generateInsertionSequence(insertionSequence);
	std::cout << "Insertion sequence: " << insertionSequence << std::endl;
	for(std::list<unsigned int>::iterator it = insertionSequence.begin(); it != insertionSequence.end(); ++it)
		--(*it);
	std::cout << "Normalized insertion sequence: " << insertionSequence << std::endl;
	_insertIntoList(pairsList, insertionSequence, odd, struggler);
	std::cout << "Main chain final: " << this->_sortedList << std::endl;
}

PmergeMe::PmergeMe(int argc, char **argv)
{
//	// Input validation
//	if (input.find_first_not_of("0123456789 ") != std::string::npos)
//		throw(std::invalid_argument("Invalid characters provided on the input."));
	
	// Reserve space for vector 
	this->_vector.reserve(argc - 1);	
	this->_sortedVector.reserve(argc - 1);

	// Fill containers
	for (int i = 1; i < argc; i++)
		this->_list.push_back(std::atoi(argv[i]));
	for (int i = 1; i < argc; i++)
		this->_vector.push_back(std::atoi(argv[i]));
	
	// Print original input
	std::cout << "Vector: " << this->_vector << std::endl;
	std::cout << "List: " << this->_list << std::endl;
	if (this->_list.size() > 1)
		_sort(this->_list);
}

std::ostream	&operator << (std::ostream &o, std::list<unsigned int> &list)
{
	for(std::list<unsigned int>::iterator it = list.begin(); it != list.end(); ++it)
		o << *it << ' ';
	return (o);
}

std::ostream	&operator << (std::ostream &o, std::list< std::pair<unsigned int, unsigned int> > &list)
{
	for(std::list< std::pair<unsigned int, unsigned int> >::iterator it = list.begin(); it != list.end(); ++it)
		o << '|' << it->first << ' ' << it->second << '|' << ' ';
	return (o);
}

std::ostream	&operator << (std::ostream &o, std::vector<unsigned int> &vector)
{
	for(std::vector<unsigned int>::iterator it = vector.begin(); it != vector.end(); ++it)
		o << *it << ' ';
	return (o);
}
