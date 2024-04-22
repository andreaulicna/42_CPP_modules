/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 23:43:17 by aulicna           #+#    #+#             */
/*   Updated: 2024/04/23 00:54:28 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>
#include <vector>
#include <deque>

int main()
{
	{
		std::cout << "__SUBJECT MAIN (on MutantStack)__\n"; 
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
		std::cout << std::endl;
	}
	{
		std::cout << "__SUBJECT MAIN (on std::list)__\n"; 
		std::list<int> mstack;
		mstack.push_back(5);
		mstack.push_back(17);
		std::cout << mstack.back() << std::endl;
		mstack.pop_back();
		std::cout << mstack.size() << std::endl;
		mstack.push_back(3);
		mstack.push_back(5);
		mstack.push_back(737);
		mstack.push_back(0);
		std::list<int>::iterator it = mstack.begin();
		std::list<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::list<int> s(mstack);
		std::cout << std::endl;
	}
	{
		MutantStack<char>	mstack;
		const MutantStack<char>	*theStack;
		std::string			str = "42istheAnswer";
		
		std::cout << "__MY MAIN (on MutantStack)__\n";
		for(std::string::size_type i = 0; i < str.size(); i++)
			mstack.push(str[i]);
		theStack = &mstack;
		MutantStack<char>::const_iterator it = (*theStack).begin();
		MutantStack<char>::const_iterator ite = (*theStack).end();
		std::cout << "|";
		while (it != ite)
		{
			std::cout << *it << "|";
			++it;
		}
		std::cout << std::endl;
	}
	{
		std::deque<char> mstack;
		const std::deque<char>* theStack;
		std::string str = "42istheAnswer";

		std::cout << "\n__MY MAIN (on std::deque)__\n";
		for(std::string::size_type i = 0; i < str.size(); i++)
			mstack.push_back(str[i]);
		theStack = &mstack;
		std::deque<char>::const_iterator it = theStack->begin();
		std::deque<char>::const_iterator ite = theStack->end();
		std::cout << "|";
		while (it != ite)
		{
			std::cout << *it << "|";
			++it;
		}
		std::cout << std::endl;
	}
	{
		std::vector<char> mstack;
		const std::vector<char>* theStack;
		std::string str = "42istheAnswer";

		std::cout << "\n__MY MAIN (on std::vector)__\n";
		for(std::string::size_type i = 0; i < str.size(); i++)
			mstack.push_back(str[i]);
		theStack = &mstack;
		std::vector<char>::const_iterator it = theStack->begin();
		std::vector<char>::const_iterator ite = theStack->end();
		std::cout << "|";
		while (it != ite)
		{
			std::cout << *it << "|";
			++it;
		}
		std::cout << std::endl;
	}
	{
		MutantStack<int>			mstack;
		MutantStack<int>::iterator	it;
		MutantStack<int>::iterator	ite;

		std::cout << "\n__MY MAIN (const vs non-const)__\n";
		for(int i = 0; i < 15; i++)
			mstack.push(i);
		it = mstack.begin();
		ite = mstack.end();
		std::cout << "|";
		while (it != ite)
		{
			std::cout << *it << "|";
			++it;
		}
		std::cout << std::endl;
		it = mstack.begin();
		while (it != ite)
		{
			*it *= 2;
			++it;
		}
		std::cout << "|";
		it = mstack.begin();
		while (it != ite)
		{
			std::cout << *it << "|";
			++it;
		}
		std::cout << std::endl;
	}
//	The below won't compile due to the iterator trying to change
//	a const object
//	{
//		MutantStack<int>					mstack;
//		const MutantStack<int>				*theStack;
//		MutantStack<int>::const_iterator	it;
//		MutantStack<int>::const_iterator	ite;
//
//		std::cout << "\n__MY MAIN (const vs non-const)__\n";
//		for(int i = 0; i < 15; i++)
//			mstack.push(i);
//		it = mstack.begin();
//		ite = mstack.end();
//		std::cout << "|";
//		while (it != ite)
//		{
//			std::cout << *it << "|";
//			++it;
//		}
//		std::cout << std::endl;
//		theStack = &mstack;
//		it = (*theStack).begin();
//		while (it != ite)
//		{
//			*it *= 2;
//			++it;
//		}
//		std::cout << "|";
//		it = (*theStack).begin();
//		while (it != ite)
//		{
//			std::cout << *it << "|";
//			++it;
//		}
//		std::cout << std::endl;
//	}
//	The below won't compile due to the object being const, hence returning
//	const iterators from begin & and, but trying to assign them
//	to a non-constant operator
//	{
//		MutantStack<char>	mstack;
//		const MutantStack<char>	*theStack;
//		std::string			str = "42istheAnswer";
//		
//		std::cout << "__MY MAIN (on MutantStack {const obj, non-const its})__\n";
//		for(std::string::size_type i = 0; i < str.size(); i++)
//			mstack.push(str[i]);
//		theStack = &mstack;
//		MutantStack<char>::iterator it = (*theStack).begin();
//		MutantStack<char>::iterator ite = (*theStack).end();
//		std::cout << "|";
//		while (it != ite)
//		{
//			std::cout << *it << "|";
//			++it;
//		}
//		std::cout << std::endl;
//	}
	return (0);
}
