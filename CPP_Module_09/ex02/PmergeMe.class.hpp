/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.class.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 11:03:09 by aulicna           #+#    #+#             */
/*   Updated: 2024/04/29 16:11:14 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_CLASS_HPP
# define PMERGEME_CLASS_HPP

# include <iostream>
# include <list>
# include <vector>
# include <sstream>
# include <algorithm>

class PmergeMe
{
	public:
		PmergeMe(int argc, char **argv);
		PmergeMe(const PmergeMe& copy);
		PmergeMe	&operator=(const PmergeMe &src);
		~PmergeMe(void);
	
	private:
		PmergeMe(void);
		std::list<unsigned int>		_list;
		std::list<unsigned int>		_sortedList;
		std::vector<unsigned int>	_vector;
		std::vector<unsigned int>	_sortedVector;

		void													_sort(std::list<unsigned int> &list);
		void													_sort(std::vector<unsigned int> &vector);
		std::list< std::pair<unsigned int, unsigned int> >		_makeAndSortPairs(std::list<unsigned int> &list);
		std::vector< std::pair<unsigned int, unsigned int> >	_makeAndSortPairs(std::vector<unsigned int> &vector);
		void													_insert(std::list< std::pair<unsigned int, unsigned int> > pairsList,
																	std::list<unsigned int> insertionSequence, bool odd, unsigned int straggler);
		void													_insert(std::vector< std::pair<unsigned int, unsigned int> > pairsVector,
																   std::vector<unsigned int> insertionSequence, bool odd, unsigned int straggler);
		unsigned int											_jacobsthalNumber(unsigned int iJacobsthal);

		template <typename T>
		void	printContainer(const T &container, const std::string containerName)
		{
			std::cout << containerName << " ";
			for (typename T::const_iterator it = container.begin(); it != container.end(); ++it)
				std::cout << *it << ' ';
			std::cout << std::endl;
		}

		template <typename Container>
		Container	_generateJacobsthalSequence(unsigned int size)
		{
			Container	sequenceJacobsthal;
			unsigned int	iJacobsthal;

			iJacobsthal = 3;
			while (size > _jacobsthalNumber(iJacobsthal))
			{
				sequenceJacobsthal.push_back(_jacobsthalNumber(iJacobsthal));
				iJacobsthal++;
			}
			sequenceJacobsthal.push_back(_jacobsthalNumber(iJacobsthal));
			return (sequenceJacobsthal);
		}

		template <typename Container>
		Container _generateInsertionSequence(Container jacobsthalSequence)
		{
			Container		insertionSequence;
			unsigned int	currentValue;
			unsigned int	previousValue;

			previousValue = 1;
			for(typename Container::iterator it = jacobsthalSequence.begin(); it != jacobsthalSequence.end(); ++it)
			{
				currentValue = *it;
				insertionSequence.push_back(currentValue);
				for (size_t j = 1; currentValue - j > previousValue; j++)
					insertionSequence.push_back(currentValue - j);
				previousValue = currentValue;
			}
			return (insertionSequence);
		}
		
		struct compare
		{
			bool operator()(const std::pair<unsigned int, unsigned int>& a, const std::pair<unsigned int, unsigned int>& b)
			{
				return (a.first < b.first);
			}
		};
};

std::ostream	&operator << (std::ostream &o, std::list<unsigned int> &list);
std::ostream	&operator << (std::ostream &o, std::list< std::pair<unsigned int, unsigned int> > &list);
std::ostream	&operator << (std::ostream &o, std::vector<unsigned int> &vector);
std::ostream	&operator << (std::ostream &o, std::vector< std::pair<unsigned int, unsigned int> > &vector);

#endif
