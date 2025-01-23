/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 07:56:31 by ogoman            #+#    #+#             */
/*   Updated: 2024/11/12 08:36:33 by ogoman           ###   ########.fr       */
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

		int getRawBits() const;			   // Returns the raw fixed-point value
		void setRawBits(int const number); // Sets the raw fixed-point value

////////////////// **ex 01 **///////////////////////////
		
		Fixed(const int integer);
		Fixed(const float floating_point);

		float toFloat(void) const;
		int toInt(void) const;

////////////////// **ex 02 **///////////////////////////

		//* Overload operator
		bool operator>(const Fixed &other) const;
		bool operator<(const Fixed &other) const;
		bool operator>=(const Fixed &other) const;
		bool operator<=(const Fixed &other) const;
		bool operator==(const Fixed &other) const;
		bool operator!=(const Fixed &other) const;

		Fixed operator+(const Fixed &other) const;
		Fixed operator-(const Fixed &other) const;
		Fixed operator*(const Fixed &other) const;
		Fixed operator/(const Fixed &other) const;

		Fixed operator++();   // Prefix increment
		Fixed operator++(int); // Postfix increment
		Fixed operator--();   // Prefix decrement
		Fixed operator--(int); // Postfix decrement

		//* Static methods min and max
		static Fixed &min(Fixed &a, Fixed &b);
		static const Fixed &min(const Fixed &a, const Fixed &b);
		static Fixed &max(Fixed &a, Fixed &b);
		static const Fixed &max(const Fixed &a, const Fixed &b);

};

//* Overload of the insertion operator to output fixed-point numbers as floats
std::ostream &operator<<(std::ostream &stream, Fixed const &fixed);

#endif