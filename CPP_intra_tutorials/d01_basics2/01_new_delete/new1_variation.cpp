/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new1_variation.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 12:10:19 by aulicna           #+#    #+#             */
/*   Updated: 2024/01/12 18:13:00 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class Student
{
private:
	std::string	_login;
public:
	Student() : _login("ldefault")
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
	Student	*students = new Student[42];

	// Do some stufff here
	delete [] students;
	return(0);
}