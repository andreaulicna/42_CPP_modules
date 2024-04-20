/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 22:06:15 by aulicna           #+#    #+#             */
/*   Updated: 2024/04/20 22:28:42 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_CLASS_HPP
# define BASE_CLASS_HPP

# include <cstdlib>
# include <iostream>
# include <ctime>

class Base
{
	public:
		virtual ~Base(void);

		static Base	*generate(void);
		static void	identify(Base* p);
		static void	identify(Base& p);		
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

#endif
