/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 12:31:02 by aulicna           #+#    #+#             */
/*   Updated: 2024/03/27 23:01:44 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

# include <iostream>
# include "AMateria.class.hpp"

class AMateria;

class ICharacter
{
public:
	virtual	~ICharacter() {}
	virtual	std::string const	&getName() const = 0;
	virtual void	getInventory(void) const = 0;
	virtual	void	equip(AMateria* m) = 0;
	virtual	void	unequip(int idx) = 0;
	virtual	void	use(int idx, ICharacter& target) = 0;
};

#endif

