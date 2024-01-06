/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 17:20:42 by aulicna           #+#    #+#             */
/*   Updated: 2024/01/06 17:38:20 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Sample.class.hpp"

/*
From within the constructor both, the public and private, member attributes
can be accesed.
*/
Sample::Sample(void)
{
    std::cout << "Constructor called" << std::endl;

    this->publicFoo = 0;
    std::cout << "this->publicFoo: " << this->publicFoo << std::endl;
    this->_privateFoo = 0;
    std::cout << "this->_privateFoo: " << this->_privateFoo << std::endl;

    this->publicBar();
    this->_privateBar();

    return ;
}

Sample::~Sample(void)
{
    std::cout << "Destructor called" << std::endl;
    return ;
}

void    Sample::publicBar(void) const
{
    std::cout << "Member function publicBar called" << std::endl;
    return ;
}

void    Sample::_privateBar(void) const
{
    std::cout << "Member function _privateBar called" << std::endl;
    return ;
}
