/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.class.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 10:44:13 by aulicna           #+#    #+#             */
/*   Updated: 2024/03/26 11:16:04 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_CLASS_HPP
# define WRONGCAT_CLASS_HPP

# include <iostream>
#include "WrongAnimal.class.hpp"

class WrongCat : public WrongAnimal
{
public:
	// Default constructor
	WrongCat(void);
	// Copy constructor
	WrongCat(const WrongCat& copy);
	// Copy assignment operator overload
	WrongCat	&operator=(const WrongCat &src);
	// Destructor
	~WrongCat(void);

	// Other member functions
	void	makeSound(void) const;

private:

};

#endif
