/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.class.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 18:04:35 by aulicna           #+#    #+#             */
/*   Updated: 2024/03/20 15:50:17 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_CLASS_HPP
# define SCAVTRAP_CLASS_HPP

# include <iostream>
# include "ClapTrap.class.hpp"

class ScavTrap : virtual public ClapTrap
{
public:
    // Default constructor
    ScavTrap(void);
    // Consturctor overloads
    ScavTrap(std::string name);
    // Copy constructor
    ScavTrap(const ScavTrap& copy);
    // Copy assignment operator overload
    ScavTrap	&operator=(const ScavTrap &src);
    // Destructor
    ~ScavTrap(void);

    // Getters
    bool    getOnGuard(void) const;
	// Member functions
	void	attack(const std::string& target);
    void    guardGate(void);

private:
    bool    _onGuard;

};

std::ostream &operator << (std::ostream &o, ScavTrap const &instance);

#endif
