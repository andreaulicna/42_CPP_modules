/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.class.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:56:00 by aulicna           #+#    #+#             */
/*   Updated: 2024/04/27 10:46:33 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_CLASS_HPP
# define RPN_CLASS_HPP

# include <iostream>
# include <stack>
# include <algorithm>
# include <cctype>

class RPN
{
	public:
		RPN(const std::string &input);
		RPN(const RPN& copy);
		RPN	&operator=(const RPN &src);
		~RPN(void);
	
	private:
		RPN(void);
		std::stack<int>	_stack;

		// void	printStack(void) const;
};

#endif
