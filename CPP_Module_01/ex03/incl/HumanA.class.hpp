/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 19:28:08 by aulicna           #+#    #+#             */
/*   Updated: 2024/01/18 20:57:30 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_CLASS_HPP
# define HUMANA_CLASS_HPP

# include "../incl/Weapon.class.hpp"
# include <string>

/**
 * @class HumanA
 * @brief This class represents a human that is always armed.
 *
 * @var std::string _name
 * 
 * @var Weapon &_weapon
 * @brief This is a reference to a Weapon object.
 * This attribute holds a reference to a Weapon object that the HumanA object
 * takes as an argument in its constructor. This means that when a HumanA object
 * is created, its hold a reference to the original Weapon object, not a copy
 * of it or a different Weapon object (that would be created if the weapon
 * wasn't set as a reference).
 */
class HumanA
{
public:
	/* Constructor */
	HumanA(std::string name, Weapon &weapon);
	/* Destructor */
	~HumanA();

	// Other member functions
	void	attack(void) const;

private:
	std::string	_name;
	Weapon		&_weapon;
};

#endif
