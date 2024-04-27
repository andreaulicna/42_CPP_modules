/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.class.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 11:03:09 by aulicna           #+#    #+#             */
/*   Updated: 2024/04/27 14:02:33 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_CLASS_HPP
# define PMERGEME_CLASS_HPP

# include <iostream>
# include <list>
# include <vector>
# include <sstream>
# include <algorithm>

typedef std::vector<unsigned int> vect_uint_t;

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
		std::list<unsigned int>		_orderedList;
		std::vector<unsigned int>	_vector;
		std::vector<unsigned int>	_orderedVector;
};

std::ostream	&operator << (std::ostream &o, std::vector<unsigned int> &vector);

#endif
