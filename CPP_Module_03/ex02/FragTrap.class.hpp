/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.class.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 19:14:07 by aulicna           #+#    #+#             */
/*   Updated: 2024/03/19 19:23:39 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_CLASS_HPP
# define FRAGTRAP_CLASS_HPP

# include <iostream>
# include "ClapTrap.class.hpp"

class FragTrap : public ClapTrap
{
public:
	// Default constructor
	FragTrap(void);
    // Constructor overloads
    FragTrap(std::string name);
	// Copy constructor
	FragTrap(const FragTrap& copy);
	// Copy assignment operator overload
	FragTrap	&operator=(const FragTrap &src);
	// Destructor
	~FragTrap(void);

	// Member functions
	void	highFivesGuys(void);

private:

};

std::ostream &operator << (std::ostream &o, FragTrap const &instance);

#endif