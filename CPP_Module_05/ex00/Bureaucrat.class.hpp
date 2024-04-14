/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.class.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 18:10:49 by aulicna           #+#    #+#             */
/*   Updated: 2024/04/14 18:55:06 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

# include <iostream>
# include <stdexcept>

# define HIGHEST_GRADE 1
# define LOWEST_GRADE 150

class Bureaucrat
{
	public:
		Bureaucrat(void);
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const std::string name);
		Bureaucrat(int grade);
		Bureaucrat(const Bureaucrat &copy);
		Bureaucrat	&operator = (const Bureaucrat &src);
		~Bureaucrat();

		const std::string	&getName() const;
		int					getGrade() const;
		
		void				increment();
		void				increment(int value);
		void				decrement();
		void				decrement(int value);

		Bureaucrat	&operator ++ (void);
		Bureaucrat	operator ++ (int dummy);
		Bureaucrat	&operator -- (void);
		Bureaucrat	operator -- (int dummy);

		class GradeTooLowException : public std::invalid_argument
		{
			public:
				GradeTooLowException();
				const char*		what() const throw();
		};
		class GradeTooHighException : public std::invalid_argument
		{
			public:
				GradeTooHighException();
				const char*		what() const throw();
		};

		private:
			const std::string	_name;
			int					_grade;
};

std::ostream	&operator<<(std::ostream &o, const Bureaucrat &instance);

#endif