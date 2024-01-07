/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 14:47:37 by aulicna           #+#    #+#             */
/*   Updated: 2024/01/07 15:09:28 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_H
# define CONTACT_CLASS_H

class Contact
{
public:
	// constructor
	Contact(void);
	// destructor
	~Contact(void);

	// setters
	void	setFirstName(std::string str);
	void	setLastName(std::string str);
	void	setNickname(std::string str);
	void	setPhoneNumber(std::string str);
	void	setDarkestSecrete(std::string str);

	// getters
	std::string	getFirstName(std::string str);
	std::string	getLastName(std::string str);
	std::string	getNickname(std::string str);
	std::string	getPhoneNumber(std::string str);
	std::string	getDarkestSecrete(std::string str);	

private:
	std::string	_firstName;
	std::string	_lastName;
	std::string	_nickname;
	std::string	_phoneNumber;
	std::string	_darkestSecret;
};

#endif
