/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample3.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 16:48:27 by aulicna           #+#    #+#             */
/*   Updated: 2024/01/06 17:06:32 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Sample3.class.hpp"

/*
It isn't the f value being assigned to the const pi, but the const pi being 
initialized to the f value.
*/
Sample3::Sample3(float const f): pi(f), qd(42)
{
    std::cout << "Constructor called" << std::endl;
    return ;
}

Sample3::~Sample3(void)
{
    std::cout << "Destructor called" << std::endl;
    return ;
}

/*
Using the const keyword in the definition (and also declaration) of a member
function says that that member function doesn't change the instance of a class.
That means that there won't be code like 'this->[member_attribute] = [value]'
*/
void    Sample3::bar(void) const
{
    std::cout << "this->pi = " << this->pi << std::endl;
    std::cout << "this->qd = " << this->qd << std::endl;
    return ;
}