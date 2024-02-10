/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 12:29:40 by aulicna           #+#    #+#             */
/*   Updated: 2024/02/10 13:01:14 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_CLASS_HPP
# define FIXED_CLASS_HPP

class Fixed
{
public:
	// Constructor
	Fixed(void);
	// Copy constructor
	Fixed(const Fixed& copy);
	// Destructor
	~Fixed(void);

	// Copy assignment operator overload
	Fixed	&operator=(const Fixed &src);
	// Getter
	int		getRawBits(void) const;
	// Setter
	void	setRawBits(int const raw);

private:
	int					_fixPointNumber;
	static const int	_fractionalBits;
};
#endif
