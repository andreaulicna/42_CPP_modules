/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 23:48:25 by aulicna           #+#    #+#             */
/*   Updated: 2024/01/31 17:27:00 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.class.hpp"
#include <iostream>
#include <cctype>

Harl::Harl(void)
{
	return ;
}

Harl::~Harl(void)
{
	return ;
}

void	Harl::complain(std::string level) const
{
	void	(Harl::*functionPtrs[])(void) const = {&Harl::_debug, &Harl::_info,
		&Harl::_warning, &Harl::_error};
	std::string	levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; level[i] != '\0'; i++)
		level[i] = (char)toupper(level[i]);
	for (int i = 0; i < 4; i++)
	{
		if (level == levels[i])
		{
			(this->*functionPtrs[i])();
			return ;
		}
	}
	std::cout << "Error: Invalid level." << std::endl;
}

void	Harl::_debug(void) const
{
	std::cout << "I love having extra bacon for my "
		"7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"
		<< std::endl;
}

void	Harl::_info(void) const
{
	std::cout << "I cannot believe adding extra bacon costs more money. "
		"You didn’t put enough bacon in my burger! If you did, I wouldn’t "
		"be asking for more!" << std::endl;
}

void	Harl::_warning(void) const
{
	std::cout << "I think I deserve to have some extra bacon for free. "
		"I’ve been coming for years whereas you started working here since last"
		"month." << std::endl;
}

void	Harl::_error(void) const
{
	std::cout << "This is unacceptable! I want to speak to the manager now."
		<< std::endl;
}
