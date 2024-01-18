/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 16:04:12 by aulicna           #+#    #+#             */
/*   Updated: 2024/01/13 12:10:53 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_H
# define PHONEBOOK_CLASS_H

# include <string.h>
# include <iomanip>
# include <iostream>
# include "Contact.class.hpp"

class PhoneBook
{
public:
	/* Constructor */
	PhoneBook(void);
	/* Destructor */
	~PhoneBook(void);

	// Getters
	Contact	getContact(int index) const;
	int		getCountactsCount() const;

	// Other methods
	void	add(void);	
	void	search() const;

private:
	Contact	_contacts[8];
	int		_contactsCount;
};

#endif
