/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:29:21 by aulicna           #+#    #+#             */
/*   Updated: 2024/01/18 20:56:51 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_CLASS_HPP
# define WEAPON_CLASS_HPP

# include <string>

class Weapon
{
public:
	/* Constructor */
	Weapon(void);
	Weapon(std::string type);
	/* Destructor */
	~Weapon(void);

	// Getters
	std::string const	&getType(void) const;

	// Setters
	void				setType(std::string newType);

private:
	std::string	_type;
};

#endif
