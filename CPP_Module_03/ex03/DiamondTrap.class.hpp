/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.class.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 15:45:58 by aulicna           #+#    #+#             */
/*   Updated: 2024/03/20 15:50:00 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_CLASS_HPP
# define DIAMONDTRAP_CLASS_HPP

# include <iostream>
#include "FragTrap.class.hpp"
#include "ScavTrap.class.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
public:
	// Default constructor
	DiamondTrap(void);
	// Constructor overloads
	DiamondTrap(std::string name);
	// Copy constructor
	DiamondTrap(const DiamondTrap& copy);
	// Copy assignment operator overload
	DiamondTrap	&operator=(const DiamondTrap &src);
	// Destructor
	~DiamondTrap(void);

	// Other member functions
	void	whoAmI(void);

private:
	std::string	name;

};

#endif
