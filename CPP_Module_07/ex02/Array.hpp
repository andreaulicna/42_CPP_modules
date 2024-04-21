/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 10:02:07 by aulicna           #+#    #+#             */
/*   Updated: 2024/04/21 10:38:58 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <cstddef>
# include <iostream>

template <typename T> class Array
{
	public:
		Array(void);
		Array(unsigned int size);
		Array(const Array& copy);
		Array	&operator=(const Array &src);
		~Array(void);

		T& operator [] (unsigned int i);

		unsigned int	size(void) const;
		void			printArr(void) const;
	
	private:
		T*				_arr;
		unsigned int	_size;
};

# include "Array.tpp"

#endif
