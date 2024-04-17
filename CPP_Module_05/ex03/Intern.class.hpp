/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 19:34:32 by aulicna           #+#    #+#             */
/*   Updated: 2024/04/17 19:49:58 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_CLASS_HPP
# define INTERN_CLASS_HPP

# include <iostream>
# include "AForm.class.hpp"
# include "PresidentialPardonForm.class.hpp"
# include "RobotomyRequestForm.class.hpp"
# include "ShrubberyCreationForm.class.hpp"


class Intern
{
	public:
		Intern(void);
		Intern(const Intern& copy);
		Intern	&operator=(const Intern &src);
		~Intern(void);

		AForm	*makeForm(const std::string name, const std::string target);

		class UnknownFormNameException : public std::invalid_argument
		{
			public:
				UnknownFormNameException();
				const char*	what() const throw();
		};
private:
};

#endif
