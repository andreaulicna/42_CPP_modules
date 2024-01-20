/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 11:13:32 by aulicna           #+#    #+#             */
/*   Updated: 2024/01/19 20:38:24 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

# include <iostream>

class Zombie
{
public:
	/* Constructor */
	Zombie(std::string name);
	Zombie(void);
	/* Destructor */
	~Zombie();

	// Setters
	void	setName(std::string name);
	
	// Other member functions
	void	announce(void) const;

private:
	std::string	_name;
};

Zombie	*zombieHorde(int N, std::string name);

#endif
