/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.class.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 11:03:01 by aulicna           #+#    #+#             */
/*   Updated: 2024/04/29 16:08:28 by aulicna          ###   ########.fr       */
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

std::list< std::pair<unsigned int, unsigned int> >	PmergeMe::_makeAndSortPairs(std::list<unsigned int> &list)
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
	pairsList.sort(compare());
	return (pairsList);
}

void PmergeMe::_insert(std::list< std::pair<unsigned int, unsigned int> > pairsList,
							   std::list<unsigned int> insertionSequence, bool odd, unsigned int straggler)
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
		}
	}
	if (odd)
	{
		itSortedList = std::upper_bound(this->_sortedList.begin(), this->_sortedList.end(), straggler);
		this->_sortedList.insert(itSortedList, straggler);
	}
}

void	PmergeMe::_sort(std::list<unsigned int> &list)
{
	bool												odd;
	unsigned int										straggler;
	std::list< std::pair<unsigned int, unsigned int> >	pairsList;
	std::list<unsigned int>								insertionSequence;

	// Check for odd sequence and save straggler if so
	odd = false;
	if (list.size() % 2 == 1)
	{
		odd = true;
		straggler = list.back();
		list.pop_back();
	}
	// Make pairs and put the larger number of within the pair as the first one
	pairsList = _makeAndSortPairs(list);
	// Main chain and pend
	for(std::list< std::pair<unsigned int, unsigned int> >::iterator it = pairsList.begin(); it != pairsList.end(); ++it)
		this->_sortedList.push_back(it->first);
	// First element of pend to the main chain
	this->_sortedList.push_front(pairsList.begin()->second);
	insertionSequence = _generateJacobsthalSequence<std::list <unsigned int> >(pairsList.size());
	// Jacob and insertion sequences
	insertionSequence = _generateInsertionSequence(insertionSequence);
	// "Normalize" the insertion sequence
	for(std::list<unsigned int>::iterator it = insertionSequence.begin(); it != insertionSequence.end(); ++it)
		--(*it);
	_insert(pairsList, insertionSequence, odd, straggler);
	std::cout << "After: " << this->_sortedList << std::endl;
}

std::vector< std::pair<unsigned int, unsigned int> >	PmergeMe::_makeAndSortPairs(std::vector<unsigned int> &vector)
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
	std::sort(pairsList.begin(), pairsList.end(), compare());
	return (pairsList);
}

void PmergeMe::_insert(std::vector< std::pair<unsigned int, unsigned int> > pairsVector,
							   std::vector<unsigned int> insertionSequence, bool odd, unsigned int straggler)
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
		}
	}
	if (odd)
	{
		itToInsertTo = std::upper_bound(this->_sortedVector.begin(), this->_sortedVector.end(), straggler);
		this->_sortedVector.insert(itToInsertTo, straggler);
	}
}

void	PmergeMe::_sort(std::vector<unsigned int> &vector)
{
	bool													odd;
	unsigned int											straggler;
	std::vector< std::pair<unsigned int, unsigned int> >	pairsVector;
	std::vector<unsigned int>								insertionSequence;

	// Check for odd sequence and save straggler if so
	odd = false;
	if (vector.size() % 2 == 1)
	{
		odd = true;
		straggler = vector.back();
		vector.pop_back();
	}
	// Make pairs and put the larger number of within the pair as the first one
	pairsVector = _makeAndSortPairs(vector);
	// Main chain and pend
	for(size_t i = 0; i < pairsVector.size(); i++)
		this->_sortedVector.push_back(pairsVector[i].first);
	// First element of pend to the main chain
	this->_sortedVector.insert(_sortedVector.begin(), pairsVector[0].second);
	insertionSequence = _generateJacobsthalSequence<std::vector <unsigned int> >(pairsVector.size());
	// Jacob and insertion sequences
	insertionSequence = _generateInsertionSequence(insertionSequence);
	// "Normalize" the insertion sequence
	for(size_t i = 0; i < insertionSequence.size(); i++)
		insertionSequence[i] -= 1;
	_insert(pairsVector, insertionSequence, odd, straggler);
}

PmergeMe::PmergeMe(int argc, char **argv)
{
	clock_t		start;
	clock_t		finish;

	// Reserve space for vector 
	this->_vector.reserve(argc - 1);	
	this->_sortedVector.reserve(argc - 1);
	// Fill containers
	for (int i = 1; i < argc; i++)
		this->_list.push_back(std::atoi(argv[i]));
	for (int i = 1; i < argc; i++)
		this->_vector.push_back(std::atoi(argv[i]));
	std::cout << "Before: " << this->_vector << std::endl;
	start = clock();
	if (this->_list.size() > 1)
		_sort(this->_list);
	else
		std::cout << "After: " << this->_list;
	finish = clock();
	std::cout << "Time to process a range of "<< argc - 1
		<< " elements with std::list: "
		<< static_cast<double>(finish - start) / 1000.0 << " ms" << std::endl;
	start = clock();
	if (this->_vector.size() > 1)
		_sort(this->_vector);
	finish = clock();
	std::cout << "Time to process a range of "<< argc - 1
		<< " elements with std::vector: "
		<< static_cast<double>(finish - start) / 1000.0 << " ms" << std::endl;
}

std::ostream &operator<<(std::ostream &o, std::list<unsigned int> &list)
{
	std::list<unsigned int>::iterator it;

	if (!list.empty())
	{
		it = list.begin();
		o << *it;
		++it;
		for (; it != list.end(); ++it)
			o << ' ' << *it;
	}
	return (o);
}

std::ostream	&operator << (std::ostream &o, std::list< std::pair<unsigned int, unsigned int> > &list)
{
	for(std::list< std::pair<unsigned int, unsigned int> >::iterator it = list.begin(); it != list.end(); ++it)
		o << '|' << it->first << ' ' << it->second << '|' << ' ';
	return (o);
}

std::ostream &operator<<(std::ostream &o, std::vector<unsigned int> &vector)
{
	if (!vector.empty())
	{
		o << vector[0];
		for (size_t i = 1; i < vector.size(); i++)
			o << ' ' << vector[i];
	}
	return (o);
}

std::ostream	&operator << (std::ostream &o, std::vector< std::pair<unsigned int, unsigned int> > &vector)
{
	for(size_t i = 0; i < vector.size(); i++)
		o << '|' << vector[i].first << ' ' << vector[i].second << '|' << ' ';
	return (o);
}
