/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 10:19:45 by aulicna           #+#    #+#             */
/*   Updated: 2024/03/26 11:15:56 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_CLASS_HPP
# define ANIMAL_CLASS_HPP

# include <iostream>

class Animal
{
public:
	// Default constructor
	Animal(void);
	// Copy constructor
	Animal(const Animal& copy);
	// Copy assignment operator overload
	Animal	&operator=(const Animal &src);
	// Destructor
	~Animal(void);

	// Getters
	std::string	getType(void) const;

	// Other member functions
	virtual void	makeSound(void) const;

protected:
	std::string	_type;

};

#endif
