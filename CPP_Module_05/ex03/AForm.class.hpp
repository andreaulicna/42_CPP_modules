/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 08:51:42 by aulicna           #+#    #+#             */
/*   Updated: 2024/04/15 10:20:03 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_CLASS_HPP
# define AFORM_CLASS_HPP

# include "Bureaucrat.class.hpp"

class Bureaucrat;
class AForm
{
public:
	AForm(void);
	AForm(const std::string name, int gradeSign, int gradeExec);
	AForm(const AForm& copy);
	AForm	&operator=(const AForm &src);
	virtual ~AForm(void);

	const std::string	&getName() const;
	bool				getIsSigned() const;
	const int			&getGradeSign() const;
	const int			&getGradeExec() const;

	void	beSigned(Bureaucrat &bureaucrat);
	void	checkIfExecutable(Bureaucrat const &executor) const;
	virtual void	execute(Bureaucrat const &executor) = 0;

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
	class FormNotSignedException : public std::invalid_argument
	{
		public:
			FormNotSignedException();
			const char*		what() const throw();
	};

private:
	const std::string	_name;
	bool				_isSigned;
	const int			_gradeSign;
	const int			_gradeExec;
};

std::ostream	&operator<<(std::ostream &o, const AForm &instance);

#endif
