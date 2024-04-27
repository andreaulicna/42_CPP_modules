/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.class.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:55:52 by aulicna           #+#    #+#             */
/*   Updated: 2024/04/27 10:47:36 by aulicna          ###   ########.fr       */
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

// For debugging purposes
//void RPN::printStack(void) const
//{
//	std::stack<int> stackCopy;
//	int	i;
//	
//	stackCopy = this->_stack;
//	i = 1;
//	while (!stackCopy.empty())
//	{
//		std::cout << i << ". " << stackCopy.top() << std::endl;
//		stackCopy.pop();
//		i++;
//	}
//}

static bool	isOperation(char operation)
{
	return (operation == '+' || operation == '-'
		|| operation == '*' || operation == '/');
}

static int	performOperation(char operation, int lhs, int rhs)
{
	if (operation == '+')
		return (lhs + rhs);
	else if (operation == '-')
		return (lhs - rhs);
	else if (operation == '*')
		return (lhs * rhs);
	else
	{
		if (rhs == 0)
			throw(std::invalid_argument("Division by zero."));
		return (lhs / rhs);
	}
}

RPN::RPN(const std::string &input)
{
	std::string	inputNoSpaces;
	int			lhs;
	int			rhs;

	inputNoSpaces = input;
	inputNoSpaces.erase(std::remove_if(inputNoSpaces.begin(), inputNoSpaces.end(), ::isspace), inputNoSpaces.end());
	if (inputNoSpaces.find_first_not_of("0123456789-+*/") != std::string::npos)
		throw(std::invalid_argument("Invalid characters provided on the input."));
	for(std::string::iterator it = inputNoSpaces.begin(); it != inputNoSpaces.end(); it++)
	{
		if (std::isdigit(*it))
			this->_stack.push(*it - '0');
		else if (isOperation(*it))
		{
			if (this->_stack.size() > 1)
			{
				rhs = this->_stack.top();
				this->_stack.pop();
				lhs = this->_stack.top();
				this->_stack.pop();
				this->_stack.push(performOperation(*it, lhs, rhs));
			}
			else
				throw(std::logic_error("Invalid syntax."));
		}
	}
	if (this->_stack.size() == 1)
		std::cout << this->_stack.top() << std::endl;
	else
		throw(std::logic_error("More than one number left."));
}
