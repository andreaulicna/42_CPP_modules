/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 10:19:40 by aulicna           #+#    #+#             */
/*   Updated: 2024/04/21 10:49:12 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T> Array<T>::Array(void)
{
	this->_arr = NULL;
	this->_size = 0;
}

template <typename T> Array<T>::Array(unsigned int size)
{
	this->_arr = new T[size];
	this->_size = size;
}

template <typename T> Array<T>::Array(const Array& copy)
{
	this->_arr = new T[copy._size];
	this->_size = copy._size;
	for (size_t i = 0; i < copy._size; i++)
		this->_arr[i] = copy._arr[i];
}

template <typename T> Array<T> &Array<T>::operator = (const Array &src)
{
	if (this != *src)
	{
		this->_arr = new T[src._size];
		this->_size = src._size;
		for (size_t i = 0; i < src.size; i++)
			this->_arr[i] = src._arr[i];
	}
	return (*this);
}

template <typename T> Array<T>::~Array(void)
{
	delete[] this->_arr;
}

template <typename T> T& Array<T>::operator [] (unsigned int i)
{
	if (i < 0 || i >= _size)
		throw (std::exception());
	return (this->_arr[i]);
}

template <typename T> unsigned int Array<T>::size(void) const
{
	return (this->_size);
}

template <typename T> void Array<T>::printArr(void) const
{
	for (size_t i = 0; i < this->_size; i++)
		std::cout << this->_arr[i] << " ";
	std::cout << std::endl;
}