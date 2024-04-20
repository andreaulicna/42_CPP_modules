/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.class.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 20:00:41 by aulicna           #+#    #+#             */
/*   Updated: 2024/04/20 21:34:18 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_CLASS_HPP
# define SERIALIZER_CLASS_HPP

# include <stdint.h>
# include <iostream>

struct Data
{
	char	c;
	int		i;
	float	f;
	double	d;
};

class Serializer
{
	public:
		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);

	private:
		Serializer(void);
		Serializer(const Serializer& copy);
		Serializer	&operator=(const Serializer &src);
		~Serializer(void);
};

#endif
