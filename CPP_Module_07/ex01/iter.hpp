/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 09:33:40 by aulicna           #+#    #+#             */
/*   Updated: 2024/05/03 11:28:00 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

/**
 * @brief	Applies a function to each element of an array.
 * 
 * The function pointer parameter f is expected to take a reference
 * to an object of the same type T as the array elements.
 * 
 * @tparam	T		type of the elements in the array
 * @param	address	pointer to the first element of the array
 * @param	length	number of elements in the array
 * @param	f		pointer to a function that takes a reference to an object
 * 					of type T and returns void
 */
//template <typename T> 
//void iter(T *address, size_t length, void (*f)(T&))
//{
//	for (size_t i = 0; i < length; i++)
//		f(address[i]);
//}

/**
 * @brief	Applies a function to each element of an array.
 * 
 * The function pointer parameter f is expected to take a reference
 * to an object of a potentially different type U. This could be useful if,
 * for example, we have an array of one type but a function that operates
 * on a different type.
 * 
 * @tparam	T		type of the elements in the array
 * @tparam	U		type of the parameter of the function to apply
 * @param	address	pointer to the first element of the array
 * @param	length	number of elements in the array
 * @param	f		pointer to a function that takes a reference to an object
 * 					of type U and returns void
 */
template <typename T, typename U> 
void iter(T *address, size_t length, void (*f)(U&))
{
	for (size_t i = 0; i < length; i++)
		f(address[i]);
}

template <typename T> void myPrint(T &toPrint)
{
	std::cout << toPrint << ", ";
}

#endif
