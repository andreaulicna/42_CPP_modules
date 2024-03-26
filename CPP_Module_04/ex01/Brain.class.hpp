/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 13:24:46 by aulicna           #+#    #+#             */
/*   Updated: 2024/03/26 13:41:04 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_CLASS_HPP
# define BRAIN_CLASS_HPP

# include <iostream>

class Brain
{
public:
	// Default constructor
	Brain(void);
	// Copy constructor
	Brain(const Brain& copy);
	// Copy assignment operator overload
	Brain	&operator=(const Brain &src);
	// Destructor
	~Brain(void);

private:
	std::string	_ideas[100];

};

#endif
