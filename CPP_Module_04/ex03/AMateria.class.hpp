/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.class.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 12:51:57 by aulicna           #+#    #+#             */
/*   Updated: 2024/03/27 21:53:31 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_CLASS_HPP
# define AMATERIA_CLASS_HPP

# include <iostream>
# include "ICharacter.hpp"

class ICharacter;

class AMateria
{
public:
	// Default constructor
	AMateria(void);
	// Constructor overloads
	AMateria(std::string const & type);
	// Copy constructor
	AMateria(const AMateria& copy);
	// Copy assignment operator overload
	AMateria	&operator=(const AMateria &src);
	// Destructor
	virtual	~AMateria(void);
	
	// Getters
	std::string const &getType(void) const;
	bool	getIsEquipped(void) const;

	// Setter
	void	setIsEquipped(bool state);

	// Other member functions
	virtual AMateria*	clone(void) const = 0;
	virtual void		use(ICharacter& target);

protected:
	std::string	_type;
	bool		_isEquipped;
};

#endif