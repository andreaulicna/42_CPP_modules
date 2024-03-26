/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.class.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 10:44:13 by aulicna           #+#    #+#             */
/*   Updated: 2024/03/26 11:27:17 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_CLASS_HPP
# define CAT_CLASS_HPP

# include <iostream>
#include "Animal.class.hpp"

class Cat : public Animal
{
public:
	// Default constructor
	Cat(void);
	// Copy constructor
	Cat(const Cat& copy);
	// Copy assignment operator overload
	Cat	&operator=(const Cat &src);
	// Destructor
	~Cat(void);

	// Other member functions
	void	makeSound(void) const;

private:

};

#endif
