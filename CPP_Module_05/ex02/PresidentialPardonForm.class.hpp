/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.class.hpp                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:48:18 by aulicna           #+#    #+#             */
/*   Updated: 2024/04/17 19:11:01 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_CLASS_HPP
# define PRESIDENTIALPARDONFORM_CLASS_HPP

# include "AForm.class.hpp"

class PresidentialPardonForm : public AForm
{
	public:
		PresidentialPardonForm(void);
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm& copy);
		PresidentialPardonForm	&operator=(const PresidentialPardonForm &src);
		~PresidentialPardonForm(void);
		
		void	execute(Bureaucrat const &executor);
	
	private:
		std::string	_target;
};

#endif
