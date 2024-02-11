/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 12:29:40 by aulicna           #+#    #+#             */
/*   Updated: 2024/02/11 11:05:47 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_CLASS_HPP
# define FIXED_CLASS_HPP

# include <cmath>
# include <iostream>

class Fixed
{
public:
	// Constructors
	Fixed(void);
	Fixed(const int value);
	Fixed(const float value);
	// Copy constructor
	Fixed(const Fixed& copy);
	// Destructor
	~Fixed(void);

	// Copy assignment operator overload
	Fixed	&operator = (const Fixed &src);
	// Comparison operators overloads
	bool	operator > (const Fixed &fixed) const;
	bool	operator < (const Fixed &fixed) const;
	bool	operator >= (const Fixed &fixed) const;
	bool	operator <= (const Fixed &fixed) const;
	bool	operator == (const Fixed &fixed) const;
	bool	operator != (const Fixed &fixed) const;
	// Arithmetic operators
	Fixed	operator + (const Fixed &fixed) const;
	Fixed	operator - (const Fixed &fixed) const;
	Fixed	operator * (const Fixed &fixed) const;
	Fixed	operator / (const Fixed &fixed) const;
	// Getter
	int		getRawBits(void) const;
	// Setter
	void	setRawBits(int const raw);
	// Other member functions
	float	toFloat(void) const;
	int		toInt(void) const;

private:
	int					_fixPointNumber;
	static const int	_FRACTIONAL_BITS;
};

std::ostream &operator<<(std::ostream &o, Fixed const &instance);

#endif
