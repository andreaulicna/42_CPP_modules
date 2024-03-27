/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 10:19:45 by aulicna           #+#    #+#             */
/*   Updated: 2024/03/26 11:15:56 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_CLASS_HPP
# define WRONGANIMAL_CLASS_HPP

# include <iostream>

class WrongAnimal
{
public:
	// Default constructor
	WrongAnimal(void);
	// Copy constructor
	WrongAnimal(const WrongAnimal& copy);
	// Copy assignment operator overload
	WrongAnimal	&operator=(const WrongAnimal &src);
	// Destructor
	~WrongAnimal(void);

	// Getters
	std::string	getType(void) const;

	// Other member functions
	void	makeSound(void) const;

protected:
	std::string	_type;

};

#endif
