/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 08:51:42 by aulicna           #+#    #+#             */
/*   Updated: 2024/04/15 10:20:03 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_CLASS_HPP
# define FORM_CLASS_HPP

# include "Bureaucrat.class.hpp"

class Bureaucrat;
class Form
{
public:
	Form(void);
	Form(const std::string name, int gradeSign, int gradeExec);
	Form(const Form& copy);
	Form	&operator=(const Form &src);
	~Form(void);

	const std::string	&getName() const;
	bool				getIsSigned() const;
	const int			&getGradeSign() const;
	const int			&getGradeExec() const;

	void				beSigned(Bureaucrat &bureaucrat);

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
	bool				_isSigned;
	const int			_gradeSign;
	const int			_gradeExec;
};

std::ostream	&operator<<(std::ostream &o, const Form &instance);

#endif
