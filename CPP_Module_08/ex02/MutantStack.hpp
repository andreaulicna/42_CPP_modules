/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 23:17:33 by aulicna           #+#    #+#             */
/*   Updated: 2024/04/23 00:30:01 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>

template <class T>
class MutantStack : public std::stack<T>
{
	public:
		typedef typename std::stack<T>::container_type::iterator iterator;
	    typedef typename std::stack<T>::container_type::const_iterator const_iterator;

		MutantStack(void);
		MutantStack(const MutantStack& copy);
		MutantStack	&operator=(const MutantStack &src);
		~MutantStack(void);

		iterator	end(void);
		iterator	begin(void);
		const_iterator	begin(void) const;
		const_iterator	end(void) const;
};

# include "MutantStack.tpp"

#endif
