/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:16:24 by aulicna           #+#    #+#             */
/*   Updated: 2024/04/20 22:42:09 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.class.hpp"

int	main(void)
{
	Base	*one;
	Base	*two;
	Base	*three;

	srand(time(0));
	one = Base::generate();
	two = Base::generate();
	three = Base::generate();

	std::cout << "\n__One__" << std::endl;
	Base::identify(one);
	Base::identify(*one);	
	std::cout << "\n__Two__" << std::endl;
	Base::identify(two);
	Base::identify(*two);
	std::cout << "\n__Three__" << std::endl;
	Base::identify(three);
	Base::identify(*three);	
	std::cout << std::endl;
	delete one;
	delete two;
	delete three;
	return (0);
}