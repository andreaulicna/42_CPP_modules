/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 12:30:12 by aulicna           #+#    #+#             */
/*   Updated: 2024/02/13 14:30:20 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.class.hpp"

const int	Fixed::_FRACTIONAL_BITS = 8;

Fixed::Fixed(void): _fixPointNumber(0)
{
	//std::cout << "Default constructor called" << std::endl;
}

/**
 * @brief	Int constructor.
 * 
 * To convert an integer to a fixed point number, we need to shift the integer
 * value to the left by the number of fractional bits. This is because
 * in a fixed point representation, the integer part is stored in the higher
 * bits and the fractional part is stored in the lower bits.
 * 
 * value << _FRACTIONAL_BITS shifts value to the left by _FRACTIONAL_BITS bits.
 * This effectively multiplies value by 2^_FRACTIONAL_BITS, converting
 * the integer to a fixed point number.
 * 
 * @param	value	int to convert to a fixed-point numberand assign
 * 					to the new Fixed instance
*/
Fixed::Fixed(const int value)
{
	//std::cout << "Int constructor called" << std::endl;
	this->_fixPointNumber = value << this->_FRACTIONAL_BITS;
}

/**
 * @brief	Float constructor.
 * 
 * To convert a floating-point number to a fixed-point number, we need to
 * multiply the floating-point number by 2^_FRACTIONAL_BITS and then round
 * to the nearest integer. This is because in a fixed-point representation,
 * the integer part is stored in the higher bits and the fractional part is
 * stored in the lower bits.
 * 
 * Since _FRACTIONAL_BITS represents the number of fractional bits, it can be
 * used to multiply the floating-point value. The number 1 is being shifted
 * by _FRACTIONAL_BITS to create a multiplier for the floating-point value.
 * The roundf function is used to round to the nearest integer.
 * 
 * @param	value	float to convert to a fixed-point numberand assign
 * 					to the new Fixed instance
*/
Fixed::Fixed(const float value)
{
	//std::cout << "Float constructor called" << std::endl;
	this->_fixPointNumber = roundf(value * (1 << this->_FRACTIONAL_BITS));
}

/**
 * @brief	Copy constructor. It creates a new Fixed instance that is a copy
 * of an existing Fixed instance.
 * 
 * Example:
 * Used for initialization where Fixed f2(f1) will call the copy constructor,
 * which will copy the value of f1's _fixPointNumber member
 * to f2's _fixPointNumber member.
 * 
 * @param	src	constant reference to a Fixed instance to copy
*/
Fixed::Fixed(const Fixed &copy)
{
	//std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed::~Fixed(void)
{
//	std::cout << "Destructor called" << std::endl;
}

// Getter
int	Fixed::getRawBits(void) const
{
//	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixPointNumber);
}

// Setter
void	Fixed::setRawBits(int const raw)
{
	this->_fixPointNumber = raw;
}

/** 
 * @brief	Copy assignment operator for the Fixed class. It assigns the value
 * of one (already existing) Fixed instance to another.
 * 
 * if (this != &src) checks if the current instance (this) is not the same as
 * the source instance (src). This is to prevent self-assignment, which could
 * lead to unexpected behavior.
 * 
 * this->_fixPointNumber = src.getRawBits(); assigns the value of src's
 * _fixPointNumber member to the _fixPointNumber member of the current instance. 
 * 
 * Example: 
 * Used for assignment where f1 = f2 will call the copy assignment operator,
 * which will copy the value of f2's _fixPointNumber member
 * to f1's _fixPointNumber member.
 * 
 * @param	src		constant reference to a Fixed instance
 * @return	&Fixed	reference to the current instance (allows for chaining
 * 					of assignment operations)
*/
Fixed	&Fixed::operator = (const Fixed &src)
{
	//std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
		this->_fixPointNumber = src.getRawBits();
	return *this;
}

// Comparison operators overloads
bool	Fixed::operator > (const Fixed &fixed) const
{
	return (this->getRawBits() > fixed.getRawBits());	
}

bool	Fixed::operator < (const Fixed &fixed) const
{
	return (this->getRawBits() < fixed.getRawBits());	
}

bool	Fixed::operator >= (const Fixed &fixed) const
{
	return (this->getRawBits() >= fixed.getRawBits());	
}

bool	Fixed::operator <= (const Fixed &fixed) const
{
	return (this->getRawBits() <= fixed.getRawBits());	
}

bool	Fixed::operator == (const Fixed &fixed) const
{
	return (this->getRawBits() == fixed.getRawBits());	
}

bool	Fixed::operator != (const Fixed &fixed) const
{
	return (this->getRawBits() != fixed.getRawBits());	
}

// Arithmetic operators
Fixed	Fixed::operator + (const Fixed &fixed) const
{
	Fixed	toReturn;

	toReturn = this->toFloat() + fixed.toFloat();
	return (toReturn);
}

Fixed	Fixed::operator - (const Fixed &fixed) const
{
	Fixed	toReturn;

	toReturn = this->toFloat() - fixed.toFloat();
	return (toReturn);
}

Fixed	Fixed::operator * (const Fixed &fixed) const
{
	Fixed	toReturn;

	toReturn = this->toFloat() * fixed.toFloat();
	return (toReturn);
}

Fixed	Fixed::operator / (const Fixed &fixed) const
{
	Fixed	toReturn;

	toReturn = this->toFloat() / fixed.toFloat();
	return (toReturn);
}

/**
 * @brief	Overloads the pre-increment operator (++) for the Fixed class.
 * 
 * This function increments the fixed-point number stored in the object by 1.
 * The increment is done in the fixed-point representation, so it effectively
 * increments the number by the smallest representable positive number
 * in the fixed-point format.
 * 
 * @return	Fixed&	reference to the Fixed object after it has been incremented
 * 					(allows for chaining of increment operations)
 */
Fixed	&Fixed::operator ++ (void)
{
	++(this->_fixPointNumber);
	return *this;
}

/**
 * @brief	Overloads the post-increment operator (++) for the Fixed class.
 * 
 * This function creates a copy of the current object, increments
 * the fixed-point number stored in the current object by 1, and then returns
 * the copy. The increment is done in the fixed-point representation, so it
 * effectively increments the number by the smallest  representable positive
 * number in the fixed-point format.
 * 
 * @param	int		is an unused parameter used to differentiate this postfix
 * 					operator from the prefix version
 * @return	Fixed	copy of the Fixed object before it was incremented
 */
Fixed	Fixed::operator ++ (int dummy)
{
	Fixed	toReturn;

	toReturn = *this;
	this->_fixPointNumber++;
	return (toReturn);
}

/**
 * @brief	Overloads the pre-decrement operator (--) for the Fixed class.
 * 
 * This function decrements the fixed-point number stored in the object by 1.
 * The decrement is done in the fixed-point representation, so it effectively
 * decrements the number by the smallest representable positive number
 * in the fixed-point format.
 * 
 * @return	Fixed&	reference to the Fixed object after it has been decremented
 * 					(allows for chaining of decrement operations)
 */
Fixed	&Fixed::operator -- (void)
{
	--(this->_fixPointNumber);
	return *this;
}

/**
 * @brief	Overloads the post-decrement operator (--) for the Fixed class.
 * 
 * This function creates a copy of the current object, decrements
 * the fixed-point number stored in the current object by 1, and then returns
 * the copy. The decrement is done in the fixed-point representation, so it
 * effectively decrements the number by the smallest  representable positive
 * number in the fixed-point format.
 * 
 * @param	int		is an unused parameter used to differentiate this postfix
 * 					operator from the prefix version
 * @return	Fixed	copy of the Fixed object before it was decremented
 */
Fixed	Fixed::operator -- (int dummy)
{
	Fixed	toReturn;

	toReturn = *this;
	this->_fixPointNumber--;
	return (toReturn);
}

/**
 * @brief	Returns a reference (the object can be edited by the caller)
 * to the minimum of two Fixed objects.
 * 
 * This function compares the fixed-point numbers stored in two Fixed objects
 * and returns a reference to the object with the smaller number. The comparison
 * is done in the fixed-point representation.
 * 
 * When returning a reference, the caller can modify such a returned object. It
 * is useful when we want the function to provide direct access to an object
 * that it manages.
 * 
 * @param	A		reference to the first Fixed object
 * @param	b		reference to the second Fixed object
 * @return	Fixed&	reference to the Fixed object with the smaller fixed-point
 * 					number
 */
Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	if (a.getRawBits() <= b.getRawBits())
		return (a);
	return (b);
}

/**
 * @brief	Returns a reference (the object can be edited by the caller)
 * to the maximum of two Fixed objects.
 * 
 * This function compares the fixed-point numbers stored in two Fixed objects
 * and returns a reference to the object with the greater number. The comparison
 * is done in the fixed-point representation.
 * 
 * When returning a reference, the caller can modify such a returned object. It
 * is useful when we want the function to provide direct access to an object
 * that it manages.
 * 
 * @param	A		reference to the first Fixed object
 * @param	b		reference to the second Fixed object
 * @return	Fixed&	reference to the Fixed object with the greater fixed-point
 * 					number
 */
Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	if (a.getRawBits() >= b.getRawBits())
		return (a);
	return (b);
}

/**
 * @brief	Returns a constant reference (the object is read-only
 * for the caller) to the minimum of two Fixed objects.
 * 
 * This function compares the fixed-point numbers stored in two Fixed objects
 * and returns a reference to the object with the smaller number. The comparison
 * is done in the fixed-point representation.
 * 
 * Returning a constant reference to the object, prevents the caller
 * from modifying the returned object. The caller can use the object and call
 * const methods on it, but cannot change it. This is useful when we want
 * the function to provide read-only access to an object.
 * 
 * @param	A		const reference to the first Fixed object
 * @param	b		const reference to the second Fixed object
 * @return	Fixed&	const reference to the Fixed object with the smaller
 * 					fixed-point	number
 */
const Fixed	&Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() <= b.getRawBits())
		return (a);
	return (b);
}

/**
 * @brief	 Returns a constant reference (the object is read-only
 * for the caller) to the maximum of two Fixed objects.
 * 
 * This function compares the fixed-point numbers stored in two Fixed objects
 * and returns a reference to the object with the greater number. The comparison
 * is done in the fixed-point representation.
 * 
 * Returning a constant reference to the object, prevents the caller
 * from modifying the returned object. The caller can use the object and call
 * const methods on it, but cannot change it. This is useful when we want
 * the function to provide read-only access to an object.
 * 
 * @param	A		const reference to the first Fixed object
 * @param	b		const reference to the second Fixed object
 * @return	Fixed&	const reference to the Fixed object with the greater
 * 					fixed-point	number
 */
const Fixed	&Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() >= b.getRawBits())
		return (a);
	return (b);
}

/**
 * @brief	Converts fixed-point number back to a floating-point number.
 * 
 * this->_fixPointNumber is casted to float to ensure that the division
 * operation produces a floating-point result.
 * 1 << this->_FRACTIONAL_BITS creates a divisor that corresponds
 * to 2^_FRACTIONAL_BITS which is the value the fixed-point number was
 * multiplied by when it was created.
 * The fixed-point number is divided by this divisor to convert it back
 * to a floating-point number.
 * 
 * @return	float	floating-point representation of the fixed-point number
*/
float	Fixed::toFloat(void) const
{
	return ((float) (this->_fixPointNumber)
		/ (float) (1 << this->_FRACTIONAL_BITS));
}

/**
 * @brief	Converts fixed-point number back to an integer.
 * 
 * Shifting to the right by this->_FRACTIONAL_BITS effectively divides
 * this->_fixPointNumber by 2^_FRACTIONAL_BITS, discarding the fractional
 * part of the fixed-point number and leaving only the integer part.
 * 
 * @return	int	integer representation of the fixed-point number
*/
int	Fixed::toInt(void) const
{
	return (this->_fixPointNumber >> this->_FRACTIONAL_BITS);
}

/**
 *  @brief	 Overload of the insertion («) operator that inserts
 * a floating-point representation of the fixed-point number into the output
 * stream object passed as parameter.
 * 
 * The function converts the Fixed instance to a float using its toFloat member
 * function, and then outputs the resulting float to the ostream object. 
 * 
 * Example:
 * A Fixed instance f, can be output it to the console via std::cout << f. This
 * notation will call the << operator overload, which will convert f to a float
 * and output it.
 * 
 * @param	o				reference to the ostream object that the Fixed
 * 							instance will be output to	
 * @param	instance		constant reference to the Fixed instance that will
 * 							be outpu			
 * @return	std::ostream	stream object (allows for chaining of << operations)
*/
std::ostream &operator<<(std::ostream &o, Fixed const &instance)
{
	o << instance.toFloat();
	return (o);
}
