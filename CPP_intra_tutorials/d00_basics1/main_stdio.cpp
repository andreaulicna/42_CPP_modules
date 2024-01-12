/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_stdio.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 13:29:30 by aulicna           #+#    #+#             */
/*   Updated: 2024/01/06 14:04:51 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main( void ) {
    
    char    buff[512];

    std::cout << "Hello world !" << std::endl;

    std::cout << "Input a word: ";
    std::cin >> buff;
    std::cout << "You entered :[" << buff << "]" << std::endl;

    return 0;
}