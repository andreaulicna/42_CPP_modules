/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 23:09:21 by aulicna           #+#    #+#             */
/*   Updated: 2024/04/22 00:46:31 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.class.hpp"

Span::Span(void): _n(0)
{
	return ;
}

Span::Span(unsigned int n): _n(n)
{
	return ;
}

Span::Span(const Span& copy)
{
	*this = copy;
}

Span	&Span::operator = (const Span &src)
{
	if (this != &src)
	{
		this->_numbers = src._numbers;
		this->_n = src._n;		
	}
	return (*this);
}

Span::~Span(void)
{
	return ;
}

/**
 * @brief	Adds a single number to the Span.
 * 
 * @param	num					number to be added
 * @throws	std::runtime_error	if the Span is already full
 */
void	Span::addNumber(int num)
{
	if (this->_numbers.size() >= this->_n)
		throw(std::runtime_error("Span is full!"));
	this->_numbers.insert(num);
}

/**
 * @brief	Calculates the shortest span between any two numbers in the Span.
 * 
 * This function first checks if there are at least two numbers in the Span.
 * If not, it throws a runtime error.
 * 
 * Then, it creates a vector to hold the differences between adjacent numbers
 * in the Span. It uses the `std::adjacent_difference` function from the STL
 * to calculate these differences and store them in the vector.
 * 
 * Finally, it returns the smallest difference, which is the shortest span.
 * It skips the first element of the differences vector because
 * `std::adjacent_difference` produces a zero as the first element.
 * 
 * @return						shortest span
 * @throws	std::runtime_error	if there are fewer than two numbers in the Span
 */
int	Span::shortestSpan(void) const
{
	if (this->_numbers.size() < 2)
		throw std::runtime_error("Not enough numbers in span!");
	std::vector<int> differences;
	differences.reserve(this->_numbers.size());
	std::adjacent_difference(this->_numbers.begin(), this->_numbers.end(), std::back_inserter(differences));
	return (*std::min_element(differences.begin() + 1, differences.end()));
}

/**
 * @brief	Calculates the longest span between any two numbers in the Span.
 * 
 * This function first checks if there are at least two numbers in the Span.
 * If not, it throws a runtime error.
 * 
 * Then, it calculates the difference between the largest and smallest numbers
 * in the Span. It uses the `rbegin` and `begin` functions to get iterators
 * pointing to the largest and smallest numbers, respectively.
 * 
 * The `rbegin` function returns a reverse iterator pointing to the last
 * element, which is the largest number because the numbers are stored
 * in a multiset (which is ordered). The `begin` function returns an iterator
 * pointing to the first element, which is the smallest number.
 * 
 * Finally, it returns the difference between the largest and smallest numbers,
 * which is the longest span.
 * 
 * @return	longest span
 * @throws	std::runtime_error	if there are fewer than two numbers in the Span
 */
int Span::longestSpan(void) const
{
	if (this->_numbers.size() < 2)
		throw std::runtime_error("Not enough numbers in span!");
	return (*(this->_numbers.rbegin()) - *(this->_numbers.begin()));
}
/**
 * @brief	Prints the numbers currently in the Span.
 * 
 * The function iterates over all the numbers in the Span and in each iteration,
 * it prints the current number pointed to by the iterator `it`.
 * 
 * Then, it sets `next_it` to point to the next number in the Span by assigning
 * `it` to `next_it` and incrementing `next_it`. If `next_it` does not point
 * to the end of the Span (which means there are more numbers to print), it
 * prints a comma and a space to separate the current number from the next one.
 * 
 * Finally, after the for loop, it prints a newline character to the standard
 * output to end the line of numbers.
 * 
 * Note: The numbers are stored in a multiset, which is an ordered set.
 * Therefore, the numbers are printed in ascending order.
 */
void	Span::printNumbers(void) const
{
	std::multiset<int>::iterator next_it;

	std::cout << "Current content: ";
	for (std::multiset<int>::iterator it = this->_numbers.begin(); it != this->_numbers.end(); ++it)
	{
		std::cout << *it;
		next_it = it;
		++next_it;
		if (next_it != this->_numbers.end())
			std::cout << ", ";
	}
	std::cout << std::endl;
}

/**
 * @brief	Adds a range of numbers to the Span.
 * 
 * This function first checks if there is enough space in the Span to add
 * the range of numbers. It calculates the size of the range by taking
 * the absolute difference between the start and end of the range, and adds 1
 * to include both the start and end numbers. Then, it adds the current size
 * of the Span (the number of numbers already in the Span) to the size
 * of the range. If the total is greater than the maximum size
 * of the Span (`this->_n`), it throws a runtime error.
 * 
 * If the start of the range is greater than the end, it swaps the start and end
 * to ensure that the range is in ascending order.
 * 
 * Then, it enters a for loop that iterates from the start to the end
 * of the range (inclusive). In each iteration, it inserts the current number
 * into the Span.
 * 
 * Note: The numbers are stored in a multiset, which is an ordered set.
 * Therefore, the numbers are inserted in ascending order.
 * 
 * @param	start				start of the range
 * @param	end					end of the range
 * @throws	std::runtime_error	if there isn't enough space for the range
 * 								of numbers in the Span.
 */
void	Span::addManyMembers(int start, int end) 
{
	if (this->_n <= (abs(start - end)) + this->_numbers.size())
		throw(std::runtime_error("There isn't enough space for such a range of numbers in the span!"));
	if (start > end)
		std::swap(start, end);
	for (int i = start; i <= end; i++)
		this->_numbers.insert(i);
}

/**
 * @brief	Adds a range of numbers to the Span, skipping numbers according
 * to the specified span.
 * 
 * This function first checks if the span is zero. If it is, it throws a runtime
 * error because the span must be a positive number.
 * 
 * Then, it calculates the number of numbers to add (`numToAdd`) by taking
 * the absolute difference between the start and end of the range, dividing it
 * by the span, and adding 1. This gives the number of numbers in the range that
 * are multiples of the span apart from each other, including the start and end
 * numbers.
 * 
 * It then checks if there is enough space in the Span to add the numbers.
 * It adds the current size of the Span (the number of numbers already in the
 * Span) to `numToAdd`. If the total is greater than the maximum size
 * of the Span (`this->_n`), it throws a runtime error.
 * 
 * If the start of the range is greater than the end, it swaps the start and end
 * to ensure that the range is in ascending order.
 * 
 * Then, it enters a for loop that iterates from the start to the end
 * of the range (inclusive), incrementing the current number by the span in each
 * iteration. In each iteration, it inserts the current number into the Span.
 * 
 * Note: The numbers are stored in a multiset, which is an ordered set.
 * Therefore, the numbers are inserted in ascending order.
 * 
 * @param	start				start of the range
 * @param	end					end of the range
 * @param	span				number of numbers to skip between each added number
 * @throws	std::runtime_error	If span is zero or if there isn't enough space
 * 								for the range of numbers in the Span
 */
void Span::addManyMembersWithSpan(int start, int end, unsigned int span)
{
	unsigned int	numToAdd;

	if (span == 0)
		throw(std::runtime_error("Span must be a positive number!"));
	numToAdd = (abs(end - start) / span) + 1;
	if (this->_n < numToAdd + this->_numbers.size())
		throw(std::runtime_error("There isn't enough space for such a range of numbers in the span!"));
	if (start > end)
		std::swap(start, end);
	for (int i = start; i <= end; i += span)
		this->_numbers.insert(i);
}
