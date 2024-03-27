/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.class.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 10:44:13 by aulicna           #+#    #+#             */
/*   Updated: 2024/03/27 12:04:02 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_CLASS_HPP
# define CAT_CLASS_HPP

# include <iostream>
#include "AAnimal.class.hpp"
#include "Brain.class.hpp"

class Cat : public AAnimal
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

	// Getters
	void	getBrainContent(void) const;
	// Setters
	void	setIdea(std::string idea, int i);

	// Other member functions
	void	makeSound(void) const;
	void	brainDump(void)	const;

private:
	Brain	*_brain;

};

#endif
