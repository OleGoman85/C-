/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 07:57:32 by ogoman            #+#    #+#             */
/*   Updated: 2024/11/07 07:10:44 by ogoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

////////////////// **ex 00 **///////////////////////////

//*Default constructor initializes _fixedPointValue to 0
Fixed::Fixed() : _fixedPointValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

//*Copy constructor that initializes a new object from an existing one
Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

//**Assignment operator that copies the value from one object to another
Fixed	&Fixed::operator=(const Fixed &rhs)
{
	std::cout << "Copy assignation operator called" << std::endl;
	setRawBits(rhs.getRawBits());
	return *this;
}


//*Destructor that is called when an object goes out of scope
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

//* GETTER
int	Fixed::getRawBits(void) const {return _fixedPointValue;}


//* SETTER
void	Fixed::setRawBits(int const number) {_fixedPointValue = number;}


////////////////// **ex 01 **///////////////////////////

//* Constructor from int
Fixed::Fixed(const int integer)
{
	std::cout << "Int constructor called" << std::endl;
	_fixedPointValue = (integer <<_bits);
}

//* Constructor from float
Fixed::Fixed(const float floatPointValue)
{
	std::cout << "Float constructor called" << std::endl;
	_fixedPointValue = std::roundf(floatPointValue * (1 << _bits));
}

//* Converts fixed-point value to float
float	Fixed::toFloat(void) const
{
	return ((float)_fixedPointValue / (1 << _bits)); 
}

//* Converts fixed-point value to int
int		Fixed::toInt(void) const
{
	return (_fixedPointValue >> _bits);
}

std::ostream &operator<<(std::ostream &stream, Fixed const &fixed)
{
	stream << fixed.toFloat();
	return stream;
}