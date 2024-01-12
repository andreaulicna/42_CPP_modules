/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new1.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 12:10:19 by aulicna           #+#    #+#             */
/*   Updated: 2024/01/12 12:17:51 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class Student
{
private:
	std::string	_login;
public:
	Student(std::string login) : _login(login)
	{
		std::cout << "Student " << this->_login << " is born" << std::endl;
	}

	~Student()
	{
		std::cout << "Student " << this->_login << " died" << std::endl;
	}
};

int	main()
{
	Student	bob = Student("bfubar");
	Student	*jim = new Student("jfubar");

	// Do some stufff here
	delete jim; //jim is destroyed
	return(0);
}