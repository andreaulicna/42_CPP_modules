/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 16:59:32 by aulicna           #+#    #+#             */
/*   Updated: 2024/03/18 17:57:48 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.class.hpp"

int main(void)
{
    ClapTrap    A("A");
    ClapTrap    B("B");

    std::cout << A;
    std::cout << B;
    A.beRepaired(10);
    std::cout << A;
    B = A;
    std::cout << B;
    return (0);
}