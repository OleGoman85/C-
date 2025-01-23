/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:18:14 by ogoman            #+#    #+#             */
/*   Updated: 2024/11/07 07:10:01 by ogoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

////////////////// **ex 00 **///////////////////////////

// Default constructor initializes _fixedPointValue to 0
Fixed::Fixed() : _fixedPointValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

// Copy constructor that initializes a new object from an existing one
Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	setRawBits(other.getRawBits());
}

// Assignment operator that copies the value from one object to another
Fixed &Fixed::operator=(const Fixed &rhs)
{
	std::cout << "Copy assignation operator called" << std::endl;
	// Check for self-assignment
	if (this != &rhs)
	{
		setRawBits(rhs.getRawBits());
	}
	return *this;
}

// Destructor that is called when an object goes out of scope
Fixed::~Fixed() {std::cout << "Destructor called" << std::endl;}


// GETTER
int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_fixedPointValue); // Return the current raw value
}

// SETTER
void Fixed::setRawBits(int const number) {_fixedPointValue = number;}
