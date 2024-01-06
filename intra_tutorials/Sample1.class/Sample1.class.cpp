/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample1.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 16:09:51 by aulicna           #+#    #+#             */
/*   Updated: 2024/01/06 16:33:33 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Sample1.class.hpp"

Sample1::Sample1(char p1, int p2, float p3)
{
    std::cout << "Constructor called" << std::endl;

    this->a1 = p1;
    std::cout << "this->a1: " << this->a1 << std::endl;

    this->a2 = p2;
    std::cout << "this->a2: " << this->a2 << std::endl;

    this->a3 = p3;
    std::cout << "this->a3: " << this->a3 << std::endl;
    
    return;
}

Sample1::~Sample1(void)
{
    std::cout << "Destructor called" << std::endl;
    return;
}