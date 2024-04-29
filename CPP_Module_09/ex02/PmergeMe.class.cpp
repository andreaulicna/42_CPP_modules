/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.class.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 11:03:01 by aulicna           #+#    #+#             */
/*   Updated: 2024/04/29 15:24:29 by aulicna          ###   ########.fr       */
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

std::list< std::pair<unsigned int, unsigned int> >	PmergeMe::_makeAndSortPairsList(std::list<unsigned int> &list)
{
	std::list< std::pair<unsigned int, unsigned int> >	pairsList;
	unsigned int										first;
	unsigned int										second;

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
	pairsList.sort(compare());
	return (pairsList);
}

void PmergeMe::_insertIntoList(std::list< std::pair<unsigned int, unsigned int> > pairsList,
							   std::list<unsigned int> insertionSequence, bool odd, unsigned int struggler)
{
	std::list< std::pair<unsigned int, unsigned int> >::iterator	itPairsList;
	std::list<unsigned int>::iterator								itSortedList;
	unsigned int 													indexOfNumToInsert;

	for(std::list<unsigned int>::iterator it = insertionSequence.begin(); it != insertionSequence.end(); ++it)
	{
		indexOfNumToInsert = *it;
		if (indexOfNumToInsert < pairsList.size())
		{
			itPairsList = pairsList.begin();
			std::advance(itPairsList, indexOfNumToInsert);
			itSortedList = std::upper_bound(this->_sortedList.begin(), this->_sortedList.end(), itPairsList->second);
			this->_sortedList.insert(itSortedList, itPairsList->second);
			std::cout << "Inserting " << itPairsList->second << std::endl;
		}
		else
			std::cout << "Skipped non-existent index." << std::endl;
		std::cout << "Main chain update: " << this->_sortedList << std::endl;
	}
	if (odd)
	{
		itSortedList = std::upper_bound(this->_sortedList.begin(), this->_sortedList.end(), struggler);
		this->_sortedList.insert(itSortedList, struggler);
	}
}

void	PmergeMe::_sort(std::list<unsigned int> &list)
{
	bool												odd;
	unsigned int										struggler;
	std::list< std::pair<unsigned int, unsigned int> >	pairsList;
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
	pairsList = _makeAndSortPairsList(list);
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

std::vector< std::pair<unsigned int, unsigned int> >	PmergeMe::_makeAndSortPairsVector(std::vector<unsigned int> &vector)
{
	std::vector< std::pair<unsigned int, unsigned int> >	pairsList;
	unsigned int											first;
	unsigned int											second;

	for(size_t i = 0; i < vector.size(); i += 2)
	{
		first = vector[i];
		if (i + 1 < vector.size())
		{
			second = vector[i + 1];
			if (first < second)
				pairsList.push_back(std::make_pair(second, first));
			else
				pairsList.push_back(std::make_pair(first, second));
		}
	}
	std::cout << "Vector of pairs: " << pairsList << std::endl;
	std::sort(pairsList.begin(), pairsList.end(), compare());
	return (pairsList);
}

void PmergeMe::_insertIntoVector(std::vector< std::pair<unsigned int, unsigned int> > pairsVector,
							   std::vector<unsigned int> insertionSequence, bool odd, unsigned int struggler)
{
	unsigned int 													indexOfNumToInsert;
	unsigned int													numToInsert;
	std::vector<unsigned int>::iterator								itToInsertTo;

	for(size_t i = 0; i < insertionSequence.size(); i++)
	{
		indexOfNumToInsert = insertionSequence[i];
		if (indexOfNumToInsert < pairsVector.size())
		{
			numToInsert = pairsVector[indexOfNumToInsert].second;
			itToInsertTo = std::upper_bound(this->_sortedVector.begin(), this->_sortedVector.end(), numToInsert);
			this->_sortedVector.insert(itToInsertTo, numToInsert);
			std::cout << "Inserting " << numToInsert << std::endl;
		}
		else
			std::cout << "Skipped non-existent index." << std::endl;
		std::cout << "Main chain update: " << this->_sortedVector << std::endl;
	}
	if (odd)
	{
		itToInsertTo = std::upper_bound(this->_sortedVector.begin(), this->_sortedVector.end(), struggler);
		this->_sortedVector.insert(itToInsertTo, struggler);
	}
}

void	PmergeMe::_sort(std::vector<unsigned int> &vector)
{
	bool												odd;
	unsigned int										struggler;
	std::vector< std::pair<unsigned int, unsigned int> >	pairsVector;
	std::vector<unsigned int>								insertionSequence;

	// Check for odd sequence and save struggler if so
	odd = false;
	if (vector.size() % 2 == 1)
	{
		odd = true;
		struggler = vector.back();
		vector.pop_back();
	}
	// Make pairs and put the larger number of within the pair as the first one
	pairsVector = _makeAndSortPairsVector(vector);
	std::cout << "Vector of sorted pairs: " << pairsVector << std::endl;
	if (odd)
		std::cout << "Struggler: " << struggler << std::endl;
	// Main chain and pend
	for(size_t i = 0; i < pairsVector.size(); i++)
		this->_sortedVector.push_back(pairsVector[i].first);
	std::cout << "Main chain: " << this->_sortedVector << std::endl;
	// First element of pend to the main chain
	this->_sortedVector.insert(_sortedVector.begin(), pairsVector[0].second);
	std::cout << "Main chain with b1: " << this->_sortedVector << std::endl;
	insertionSequence = _generateJacobsthalSequence<std::vector <unsigned int> >(pairsVector.size());
	// Jacob and insertion sequences
	std::cout << "Jacob sequence: " << insertionSequence << std::endl;
	insertionSequence = _generateInsertionSequence(insertionSequence);
	std::cout << "Insertion sequence: " << insertionSequence << std::endl;
	for(size_t i = 0; i < insertionSequence.size(); i++)
		insertionSequence[i] -= 1;
	std::cout << "Normalized insertion sequence: " << insertionSequence << std::endl;
	_insertIntoVector(pairsVector, insertionSequence, odd, struggler);
	std::cout << "Main chain final: " << this->_sortedVector << std::endl;
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
	std::cout << "----------------------------------------------" << std::endl;
	if (this->_list.size() > 1)
		_sort(this->_list);
	std::cout << "----------------------------------------------" << std::endl;
	std::cout << "----------------------------------------------" << std::endl;
	if (this->_vector.size() > 1)
		_sort(this->_vector);
	std::cout << "----------------------------------------------" << std::endl;
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
//	for(std::vector<unsigned int>::iterator it = vector.begin(); it != vector.end(); ++it)
//		o << *it << ' ';
	for(size_t i = 0; i < vector.size(); i++)
		o << vector[i] << ' ';
	return (o);
}

std::ostream	&operator << (std::ostream &o, std::vector< std::pair<unsigned int, unsigned int> > &vector)
{
	for(size_t i = 0; i < vector.size(); i++)
		o << '|' << vector[i].first << ' ' << vector[i].second << '|' << ' ';
	return (o);
}
