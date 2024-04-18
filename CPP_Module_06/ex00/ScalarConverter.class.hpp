/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.class.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 12:22:12 by aulicna           #+#    #+#             */
/*   Updated: 2024/04/18 14:47:22 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_CLASS_HPP
# define SCALARCONVERTER_CLASS_HPP

# include <iostream>

enum	type
{
	CHAR = 1,
	INT,
	FLOAT,
	DOUBLE,
	PSEUDO,
	IMPOSSIBLE
};

class ScalarConverter
{
	public:
		static void	convert(std::string literal);
	private:
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter& copy);
		ScalarConverter	&operator=(const ScalarConverter &src);
		~ScalarConverter(void);
};

#endif
