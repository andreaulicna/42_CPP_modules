/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.class.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:55:52 by aulicna           #+#    #+#             */
/*   Updated: 2024/04/26 22:08:43 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.class.hpp"

RPN::RPN(void)
{
	return ;
}

RPN::RPN(const RPN& copy)
{
	*this = copy;
}

RPN	&RPN::operator = (const RPN &src)
{
	(void) src;
	return (*this);
}

RPN::~RPN(void)
{
	return ;
}

void RPN::printStack(void) const
{
	std::stack<int> stackCopy;
	int	i;
	
	stackCopy = this->_stack;
	i = 1;
	while (!stackCopy.empty())
	{
		std::cout << i << ". " << stackCopy.top() << std::endl;
		stackCopy.pop();
		i++;
	}
}

static bool	isOperation(char operation)
{
	return (operation == '+' || operation == '-'
		|| operation == '*' || operation == '\\');
}

RPN::RPN(const std::string &input)
{
	std::string	inputNoSpaces;
	int			lhs;
	int			rhs;

	std::cout << input << std::endl;
	inputNoSpaces = input;
	inputNoSpaces.erase(std::remove_if(inputNoSpaces.begin(), inputNoSpaces.end(), ::isspace), inputNoSpaces.end());
	std::cout << inputNoSpaces << std::endl;
	for(std::string::iterator it = inputNoSpaces.begin(); it != inputNoSpaces.end(); it++)
	{
		if (std::isdigit(*it))
			this->_stack.push(*it - '0');
		else if (isOperation(*it))
		{
			lhs = this->_stack.top();
			this->_stack.pop();
			rhs = this->_stack.top();
			this->_stack.pop();
			this->_stack.push(lhs * rhs);
		}
	}
	printStack();
}
