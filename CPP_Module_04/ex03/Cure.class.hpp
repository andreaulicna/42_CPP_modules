/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.class.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 19:04:05 by aulicna           #+#    #+#             */
/*   Updated: 2024/03/27 20:53:56 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_CLASS_HPP
# define CURE_CLASS_HPP

# include "AMateria.class.hpp"
# include "ICharacter.hpp"

class Cure : public AMateria
{
public:
	// Default constructor
	Cure(void);
	// Copy constructor
	Cure(const Cure& copy);
	// Copy assignment operator overload
	Cure	&operator=(const Cure &src);
	// Destructor
	~Cure(void);

	// Other member functions
	AMateria*	clone(void) const;
	void		use(ICharacter& target);
};

#endif
