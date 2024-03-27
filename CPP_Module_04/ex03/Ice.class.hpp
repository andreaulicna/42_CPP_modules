/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.class.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 19:04:05 by aulicna           #+#    #+#             */
/*   Updated: 2024/03/27 20:53:56 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_CLASS_HPP
# define ICE_CLASS_HPP

# include "AMateria.class.hpp"
# include "ICharacter.hpp"

class Ice : public AMateria
{
public:
	// Default constructor
	Ice(void);
	// Copy constructor
	Ice(const Ice& copy);
	// Copy assignment operator overload
	Ice	&operator=(const Ice &src);
	// Destructor
	~Ice(void);

	// Other member functions
	AMateria*	clone(void) const;
	void		use(ICharacter& target);
};

#endif
