/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 09:24:53 by aulicna           #+#    #+#             */
/*   Updated: 2024/04/21 09:30:24 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T> void swap(T& x, T& y)
{
	T	tmp;
	
	tmp = x;
	x = y;
	y = tmp;
}

template <typename T> T max(T x, T y)
{
	return ((x > y) ? x : y);
}

template <typename T> T min(T x, T y)
{
	return ((x < y) ? x : y);
}

#endif
