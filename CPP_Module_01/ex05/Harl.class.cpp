/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 23:48:25 by aulicna           #+#    #+#             */
/*   Updated: 2024/02/01 10:26:30 by aulicna          ###   ########.fr       */
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
	std::cout << "[INVALID]\n"
		"Probably complaining about insignificant problems." << std::endl;
}

void	Harl::_debug(void) const
{
	std::cout << "[DEBUG]\n"
		"I love having extra bacon for my "
		"7XL-double-cheese-triple-pickle-specialketchup burger.\n"
		"I really do!" << std::endl;
}

void	Harl::_info(void) const
{
	std::cout << "[INFO]\n"
		"I cannot believe adding extra bacon costs more money.\n"
		"You didn’t put enough bacon in my burger!\n"
		"If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::_warning(void) const
{
	std::cout << "[WARNING]\n" 
		"I think I deserve to have some extra bacon for free.\n"
		"I’ve been coming for years whereas you started working here since "
		"last month."
		<< std::endl;
}

void	Harl::_error(void) const
{
	std::cout << "[ERROR]\n"
		"This is unacceptable!\n"
		"I want to speak to the manager now."
		<< std::endl;
}
