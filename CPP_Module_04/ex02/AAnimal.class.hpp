/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 10:19:45 by aulicna           #+#    #+#             */
/*   Updated: 2024/03/27 11:42:06 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_CLASS_HPP
# define AANIMAL_CLASS_HPP

# include <iostream>

class AAnimal
{
public:
	// Default constructor
	AAnimal(void);
	// Copy constructor
	AAnimal(const AAnimal& copy);
	// Copy assignment operator overload
	AAnimal	&operator=(const AAnimal &src);
	// Destructor
	virtual ~AAnimal(void);

	// Getters
	const std::string	getType(void) const;

	// Other member functions
	virtual void	makeSound(void) const = 0;
	virtual void	brainDump(void)	const = 0;

protected:
	std::string	_type;

};

#endif
