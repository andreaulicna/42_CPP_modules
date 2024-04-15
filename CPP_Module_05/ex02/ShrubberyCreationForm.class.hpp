/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.class.hpp                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 12:53:30 by aulicna           #+#    #+#             */
/*   Updated: 2024/04/15 15:37:59 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_CLASS_HPP
# define SHRUBBERYCREATIONFORM_CLASS_HPP

# include "AForm.class.hpp"

class ShrubberyCreationForm : public AForm
{
public:
	ShrubberyCreationForm(void);
	ShrubberyCreationForm(const ShrubberyCreationForm& copy);
	ShrubberyCreationForm	&operator=(const ShrubberyCreationForm &src);
	~ShrubberyCreationForm(void);

	void	execute(Bureaucrat const &executor);

private:

};

#endif
