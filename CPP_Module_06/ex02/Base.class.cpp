/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 22:06:24 by aulicna           #+#    #+#             */
/*   Updated: 2024/04/20 22:40:11 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.class.hpp"

Base::~Base(void)
{
	return ;
}

Base	*Base::generate(void)
{
	int		randomNumber;

	randomNumber = rand() % 3;
	if (randomNumber == 0)
		return(new A());
	else if (randomNumber == 1)
		return(new B());
	else
		return (new C());
}

/**
 * @brief	Identifies the actual type of the object pointed to by p.
 * 
 * This function uses dynamic_cast to safely attempt to convert the Base pointer
 * to a pointer of a derived type (A, B, or C).
 * 
 * If the dynamic_cast succeeds, it means that p actually points to an object
 * of the derived type, and the function prints the name of the derived type.
 * If the dynamic_cast fails, it means that p does not point to an object
 * of the derived type, and the function tries the next cast.
 * If none of the casts succeed, p does not point to an object of any
 * of the expected types, and the function prints "Unknown type".
 * 
 * dynamic_cast is a special casting operator in C++ that performs a type-safe
 * cast at runtime (to ensure the validity of the cast). It is primarily used
 * for handling polymorphism.
 * 
 * @param	p 	pointer to a Base object
 */
void	Base::identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A (identified from a pointer)" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B (identified from a pointer)" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C (identified from a pointer)" << std::endl;
	else
		std::cout << "Unknown type" << std::endl;
}

/**
 * @brief	Identifies the actual type of the object referred to by p.
 * 
 * This function uses dynamic_cast to safely attempt to convert the Base
 * reference to a pointer of a derived type (A, B, or C).
 * If the dynamic_cast succeeds, it means that p actually refers to an object
 * of the derived type, and the function prints the name of the derived type.
 * If the dynamic_cast fails, it means that p does not refer to an object
 * of the derived type, and the function tries the next cast.
 * If none of the casts succeed, p does not refer to an object of any
 * of the expected types, and the function prints "Unknown type".
 * 
 * dynamic_cast is a special casting operator in C++ that performs a type-safe
 * cast at runtime (to ensure the validity of the cast). It is primarily used
 * for handling polymorphism.
 * 
 * @param	p	reference to a Base object
 */
void	Base::identify(Base& p)
{
	if (dynamic_cast<A*>(&p))
		std::cout << "A (identified from a reference)" << std::endl;
	else if (dynamic_cast<B*>(&p))
		std::cout << "B (identified from a reference)" << std::endl;
	else if (dynamic_cast<C*>(&p))
		std::cout << "C (identified from a reference)" << std::endl;
	else
		std::cout << "Unknown type" << std::endl;
}
