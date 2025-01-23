/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 08:43:19 by ogoman            #+#    #+#             */
/*   Updated: 2024/11/07 07:10:06 by ogoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

// Class representing a fixed-point number
class Fixed
{
	////////////////// **ex 00 **///////////////////////////

	private:
		int _fixedPointValue;		// Variable to store the fixed-point value
		static const int _bits = 8; // Number of fractional bits (fixed at 8)

	public:
		Fixed();							// Default constructor
		Fixed(const Fixed &other);			// Copy constructor
		Fixed &operator=(const Fixed &rhs); // Assignment operator
		~Fixed();							// Destructor

		int getRawBits() const;			// Returns the raw fixed-point value
		void setRawBits(int const number); // Sets the raw fixed-point value
};

#endif // FIXED_HPP
