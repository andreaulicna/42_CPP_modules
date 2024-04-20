/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:16:24 by aulicna           #+#    #+#             */
/*   Updated: 2024/04/20 21:35:15 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.class.hpp"

int	main(void)
{
	Data		*dataOriginal;
	Data		*dataSerialized;	
	uintptr_t	ptr;

	dataOriginal = new Data;
	dataOriginal->c = '*';
	dataOriginal->i = 42;
	dataOriginal->f = 42.0f;
	dataOriginal->d = 42.0;
	std::cout << "__Original Data__" << std::endl;
	std::cout << "char: " << dataOriginal->c << std::endl;
	std::cout << "int: " << dataOriginal->i << std::endl;
	std::cout << "float: " << dataOriginal->f << std::endl;
	std::cout << "double: " << dataOriginal->d << std::endl;
	ptr = Serializer::serialize(dataOriginal);
	std::cout << "\n***Running serialization***" << std::endl;
	dataSerialized = Serializer::deserialize(ptr);
	std::cout << "***Running deserialization***" << std::endl;
	std::cout << "Original: " << dataOriginal << std::endl;
	std::cout << "Serialized: " << dataSerialized << std::endl;
	std::cout << "\n__Serialized Data__" << std::endl;
	std::cout << "char: " << dataSerialized->c << std::endl;
	std::cout << "int: " << dataSerialized->i << std::endl;
	std::cout << "float: " << dataSerialized->f << std::endl;
	std::cout << "double: " << dataSerialized->d << std::endl;
	delete dataOriginal;
	return (0);
}