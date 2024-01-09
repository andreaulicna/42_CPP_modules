/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 16:04:12 by aulicna           #+#    #+#             */
/*   Updated: 2024/01/09 12:09:49 by aulicna          ###   ########.fr       */
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
	PhoneBook(void);
	~PhoneBook(void);

	void	add(void);	
	void	search(int index) const;
	void	displayContacts(void) const;
	void	addCheat(Contact c1, Contact c2, Contact c3, Contact c4, Contact c5, Contact c6, Contact c7, Contact c8);

private:
	Contact	_contacts[8];
	int		_contactsCount;
};

#endif