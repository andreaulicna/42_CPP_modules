/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.class.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 18:30:54 by aulicna           #+#    #+#             */
/*   Updated: 2024/04/08 18:46:13 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_CLASS_HPP
# define MATERIASOURCE_CLASS_HPP

# include <iostream>
# include "IMateriaSource.hpp"
# include "AMateria.class.hpp"

class MateriaSource : public IMateriaSource
{
public:
	// Default constructor
	MateriaSource(void);
	// Copy constructor
	MateriaSource(const MateriaSource& copy);
	// Copy assignment operator overload
	MateriaSource	&operator=(const MateriaSource &src);
	// Destructor
	~MateriaSource(void);

	// Other member
	void		learnMateria(AMateria *materia);
	AMateria*	createMateria(std::string const & type);

private:
	AMateria	*_learnInventory[4];

};

#endif
