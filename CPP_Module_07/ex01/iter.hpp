/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 09:33:40 by aulicna           #+#    #+#             */
/*   Updated: 2024/04/21 09:48:49 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T> void iter(T *address, size_t length, void (*f)(T&))
{
	for (size_t i = 0; i < length; i++)
		f(address[i]);
}

template <typename T> void print(T& toPrint)
{
	std::cout << toPrint << ", ";
}

#endif