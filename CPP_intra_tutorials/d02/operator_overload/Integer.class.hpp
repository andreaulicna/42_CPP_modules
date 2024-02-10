/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Integer.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 14:51:53 by aulicna           #+#    #+#             */
/*   Updated: 2024/02/10 15:17:28 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTEGER_CLASS_H
# define INTEGER_CLASS_H

# include <iostream>

class Integer
{
public:
	Integer(int const n);
	~Integer(void);

	int	getValue(void) const;

	Integer &operator=(Integer const &rhs);
	Integer operator+(Integer const &rhs) const;

private:
	int	_n;
};

std::ostream &operator<<(std::ostream &o, Integer const &rhs);

#endif