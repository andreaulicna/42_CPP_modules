/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 16:04:12 by aulicna           #+#    #+#             */
/*   Updated: 2024/01/08 11:38:39 by aulicna          ###   ########.fr       */
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
	void	search(int index);
	void	displayContacts(void);

private:
	Contact	_contacts[8];
	int		_contactsCount;
};

#endif