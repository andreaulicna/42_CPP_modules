/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.class.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 10:44:13 by aulicna           #+#    #+#             */
/*   Updated: 2024/03/26 11:13:52 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_CLASS_HPP
# define DOG_CLASS_HPP

# include <iostream>
#include "Animal.class.hpp"

class Dog : public Animal
{
public:
	// Default constructor
	Dog(void);
	// Copy constructor
	Dog(const Dog& copy);
	// Copy assignment operator overload
	Dog	&operator=(const Dog &src);
	// Destructor
	~Dog(void);

	// Other member functions
	void	makeSound(void) const;

private:

};

#endif
