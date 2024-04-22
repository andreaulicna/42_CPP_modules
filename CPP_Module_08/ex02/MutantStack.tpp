/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 23:37:25 by aulicna           #+#    #+#             */
/*   Updated: 2024/04/23 00:32:09 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack(void): std::stack<T>()
{
	return ;
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T>& copy): std::stack<T>(copy)
{
	return ;
}

template <typename T>
MutantStack<T>& MutantStack<T>::operator = (const MutantStack<T> &src)
{
	std::stack<T>::operator=(src);
	return *this;
}

template <typename T>
MutantStack<T>::~MutantStack(void)
{
	return ;
}

/**
 * @brief	Returns an iterator pointing to the first element
 * in the MutantStack.
 * 
 * The function calls the underlying container's begin() function and returns
 * the result. This allows for direct iteration over the elements
 * in the MutantStack from the beginning.
 * 
 * @tparam	T			type of elements in the MutantStack
 * @return	iterator	iterator to the first element in the MutantStack
 */
template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin(void)
{
	return (this->c.begin());
}

/**
 * @brief	Returns an iterator pointing to the past-the-end element
 * in the MutantStack.
 * 
 * The function calls the underlying container's end() function and returns
 * the result. This allows for direct iteration over the elements
 * in the MutantStack until the end.
 * 
 * @tparam	T			type of elements in the MutantStack
 * @return	iterator	iterator to the element following the last element
 * 						in the MutantStack
 */
template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end(void)
{
	return (this->c.end());
}

/**
 * @brief 	Returns a const_iterator pointing to the first element
 * in the MutantStack.
 * 
 * The function calls the underlying container's begin() function and returns
 * the result. This allows for direct iteration over the elements
 * in the MutantStack from the beginning.
 * 
 * The const keyword indicates that this method does not modify
 * the state of the object, and can be called on const MutantStack objects.
 * 
 * @tparam	T				type of elements in the MutantStack
 * @return	const_iterator	const_iterator to the first element
 * 							in the MutantStack
 */
template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin(void) const
{
	return (this->c.begin());
}

/**
 * @brief	Returns a const_iterator pointing to the past-the-end element
 * in the MutantStack.
 * 
 * The function calls the underlying container's end() function and returns
 * the result. This allows for direct iteration over the elements
 * in the MutantStack until the end.
 * 
 * The const keyword indicates that this method does not modify the state
 * of the object, and can be called on const MutantStack objects.
 * 
 * @tparam	T				type of elements in the MutantStack
 * @return	const_iterator	const_iterator to the element following the last
 * 							element in the MutantStack
 */
template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end(void) const
{
	return (this->c.end());
}
