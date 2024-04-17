/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 18:19:45 by aulicna           #+#    #+#             */
/*   Updated: 2024/04/17 14:54:38 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.class.hpp"
#include "PresidentialPardonForm.class.hpp"

int	main(void)
{
	std::cout << "PRESIDENTIAL FORM RIGHT" << std::endl;
	try
	{
		Form	app("app", 2, 3);
		Form	ballot;

		std::cout << app << std::endl;
		std::cout << ballot << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}