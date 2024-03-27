/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 13:24:46 by aulicna           #+#    #+#             */
/*   Updated: 2024/03/27 10:29:49 by aulicna          ###   ########.fr       */
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
	
	// Getters
	const std::string	getIdea(int i) const;
	const std::string	*getIdeaAddress(int i) const;
	// Setters
	void	setIdea(std::string idea, int i);

private:
	std::string	_ideas[100];

};

#endif
