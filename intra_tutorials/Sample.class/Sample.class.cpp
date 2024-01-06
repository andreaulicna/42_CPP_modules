/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 14:07:45 by aulicna           #+#    #+#             */
/*   Updated: 2024/01/06 16:01:36 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// define new class

#include <iostream>
#include "Sample.class.hpp"

/*
constructors and destructors in C++ don't have a return type
as they're producers
*/
Sample::Sample( void ) {

    std::cout << "Constructor called" << std::endl;

    this->foo = 42;
    std::cout << "this->foo: " << this->foo << std::endl;

    this->bar();
    
    return;

}

Sample::~Sample( void ) {

    std::cout << "Destructor called" << std::endl;
    return;

}

void    Sample::bar( void ) {

    std::cout << "Member function bar called" << std::endl;
    return;

}