/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 14:47:37 by aulicna           #+#    #+#             */
/*   Updated: 2024/02/15 17:53:34 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_H
# define CONTACT_CLASS_H

# include <iomanip>
# include <iostream>
# include <cwctype>
# include <limits>
# include <cstdlib>

class Contact
{
public:
	/* Constructor */
	Contact(void);
	/* Destructor */
	~Contact(void);

	// Setters
	void	setContact();
	void	setFirstName(std::string value);
	void	setLastName(std::string value);
	void	setNickname(std::string value);
	void	setPhoneNumber(std::string value);
	void	setDarkestSecret(std::string value);

	// Getters
	std::string	getFirstName(void) const;
	std::string	getLastName(void) const;
	std::string	getNickname(void) const;
	std::string	getPhoneNumber(void) const;
	std::string	getDarkestSecret(void) const;	

private:
	std::string	_firstName;
	std::string	_lastName;
	std::string	_nickname;
	std::string	_phoneNumber;
	std::string	_darkestSecret;
};

#endif
