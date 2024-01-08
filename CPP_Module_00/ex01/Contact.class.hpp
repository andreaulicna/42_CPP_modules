/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 14:47:37 by aulicna           #+#    #+#             */
/*   Updated: 2024/01/08 11:46:23 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_H
# define CONTACT_CLASS_H

# include <iomanip>
# include <iostream>
# include <string.h>
# include <cwctype>

class Contact
{
public:
	// Constructor
	Contact(void);
	// Destructor
	~Contact(void);

	// Setters
	void	setIndex(int index);
	void	setContact(int index);
//	void	setFirstName(std::string str);
//	void	setLastName(std::string str);
//	void	setNickname(std::string str);
//	void	setPhoneNumber(std::string str);
//	void	setDarkestSecrete(std::string str);

	// Getters
	std::string	getFirstName(void) const;
	std::string	getLastName(void) const;
	std::string	getNickname(void) const;
	std::string	getPhoneNumber(void) const;
	std::string	getDarkestSecret(void) const;	

private:
	int			_index;
	std::string	_firstName;
	std::string	_lastName;
	std::string	_nickname;
	std::string	_phoneNumber;
	std::string	_darkestSecret;
};

#endif
