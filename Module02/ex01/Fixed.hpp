/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 07:56:31 by ogoman            #+#    #+#             */
/*   Updated: 2024/11/07 07:10:50 by ogoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	////////////////// **ex 00 **///////////////////////////

	private:
		int _fixedPointValue;
		static const int _bits = 8;

	public:
		Fixed();							// Default constructor
		Fixed(const Fixed &other);			// Copy constructor
		Fixed &operator=(const Fixed &rhs); // Assignment operator
		~Fixed();							// Destructor


		int getRawBits() const;			// Returns the raw fixed-point value
		void setRawBits(int const number); // Sets the raw fixed-point value

		////////////////// **ex 01 **///////////////////////////

		Fixed(const int integer);
		Fixed(const float floating_point);

		float toFloat(void) const;
		int toInt(void) const;
};

// Overload of the insertion operator to output fixed-point numbers as floats
std::ostream &operator<<(std::ostream &stream, Fixed const &fixed);

#endif