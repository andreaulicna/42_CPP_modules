/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 20:13:57 by aulicna           #+#    #+#             */
/*   Updated: 2024/01/18 20:58:16 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_CLASS_HPP
# define HUMANB_CLASS_HPP

# include "../incl/Weapon.class.hpp"
# include <string>

/**
 * @class HumanB
 * @brief This class represents a human that not always has a weapon.
 * 
 * @var Weapon *_weapon
 * This attribute holds a pointer to a Weapon object that the HumanB object
 * can get set via setWeapon setter. Since the HumanB object doesn't always
 * have a weapon, it cannot be set as a reference.
 */
class HumanB
{
public:
	/* Constructor */
	HumanB(std::string name);
	/* Destructor */
	~HumanB();

	// Setters
	void	setWeapon(Weapon &weapon);

	// Other member functions
	void	attack(void) const;

private:
	std::string	_name;
	Weapon		*_weapon;
};

#endif
