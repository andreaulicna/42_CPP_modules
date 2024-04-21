/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 22:49:57 by aulicna           #+#    #+#             */
/*   Updated: 2024/04/21 23:57:36 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_CLASS_HPP
# define SPAN_CLASS_HPP

# include <iostream>
# include <set>
# include <algorithm>
# include <stdexcept>
# include <vector>
# include <numeric>

/**
 * std::multiset is a sorted associative container that contains elements
 * of type Key. It allows for fast retrieval of elements based on their sorted
 * order, which is less than or equal to the elements that come after it.
 * 
 * Why it is a good choice for this exercise:
 * 1. Ordering: std::multiset keeps its elements sorted. This is useful for
 * shortestSpan and longestSpan methods, as the shortest and longest spans
 * will always be between adjacent elements in a sorted set.
 * 2. Efficient insertions: std::multiset allows efficient insertions, deletions,
 * and lookups. It can insert a new element or delete an existing element
 * in logarithmic time.
 * 3. Size limit: We can easily enforce the size limit in addNumber method
 * by checking the size of the std::multiset before adding a new number.
 * 4. Handling duplicates: std::multiset allows duplicate elements.
*/

class Span
{
	public:
		Span(void);
		Span(unsigned int n);
		Span(const Span& copy);
		Span	&operator=(const Span &src);
		~Span(void);

		void	addNumber(int num);
		int		shortestSpan(void) const;
		int		longestSpan(void) const;
		void	printNumbers(void) const;
		void	addManyMembers(int start, int end); 
		void	addManyMembersWithSpan(int start, int end, unsigned int span); 
	
	private:
		std::multiset<int>	_numbers;
		unsigned int		_n;
};

#endif
