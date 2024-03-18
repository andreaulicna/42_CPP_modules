/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.class.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:42:13 by aulicna           #+#    #+#             */
/*   Updated: 2024/03/18 17:44:29 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_CLASS_HPP
# define CLAPTRAP_CLASS_HPP

# include <iostream>

class ClapTrap
{
public:
    // Default constructor
    ClapTrap(void);
	// Constructor overloads
	ClapTrap(std::string name);
	// Copy constructor
	ClapTrap(const ClapTrap& copy);
	// Copy assignment operator overload
	ClapTrap	&operator=(const ClapTrap &src);
	// Destructor
	~ClapTrap(void);

	// Getters
	std::string	getName(void) const;
	int			getHitPoints(void) const;
	int			getEnergyPoints(void) const;
	int			getAttackDamage(void) const;
	// Member functions
	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

private:
	std::string	_name;
	int			_hitPoints;
	int			_energyPoints;
	int			_attackDamage;
};

std::ostream &operator << (std::ostream &o, ClapTrap const &instance);

#endif
