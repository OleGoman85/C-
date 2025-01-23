/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 07:40:53 by ogoman            #+#    #+#             */
/*   Updated: 2024/12/11 12:25:18 by ogoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <limits>
#include <cmath>

// Private constructor/destructor to prevent instantiation
/*

ScalarConverter::ScalarConverter() {}
ScalarConverter::~ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &obj) {}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &rhs)
{
	return *this;
}

*/

void ScalarConverter::convert(const std::string &literal)
{
	char c;
	int i;
	float f;
	double d;

	try
	{
		if (literal.length() == 1 && !isdigit(literal[0]))
		{
			// CHAR 'a'
			c = literal[0];
			i = static_cast<int>(c);
			f = static_cast<float>(c);
			d = static_cast<double>(c);
		}
		else if (literal.find('f') != std::string::npos)
		{
			// FLOAT (contains 'f')
			f = std::stof(literal);
			c = static_cast<char>(f);
			i = static_cast<int>(f);
			d = static_cast<double>(f);
		}
		else if (literal == "nan" || literal == "+inf" || literal == "-inf")
		{
			// special DOUBLE value
			d = std::stod(literal);
			c = 0; // Conversion to char is not possible
			i = 0;
			f = static_cast<float>(d);
		}
		else
		{
			// If the input is an int or double
			d = std::stod(literal);
			c = static_cast<char>(d);
			i = static_cast<int>(d);
			f = static_cast<float>(d);
		}

		//! Output results CHAR
		std::cout << "char: ";
		if (std::isfinite(d) && d >= std::numeric_limits<char>::min() && d <= std::numeric_limits<char>::max())
		{
			if (std::isprint(static_cast<char>(d)))
				std::cout << "'" << static_cast<char>(d) << "'" << std::endl; // Printable char
			else
				std::cout << "Non displayable" << std::endl; // Non-printable char
		}
		else
		{
			std::cout << "impossible" << std::endl; // Conversion to char impossible
		}
			
		//! Output results INT
		std::cout << "int: ";
		if (std::isfinite(d) && (d >= std::numeric_limits<int>::min() && d <= std::numeric_limits<int>::max()))
			std::cout << i << std::endl; // Valid int conversion
		else
			std::cout << "impossible" << std::endl; // Conversion to int impossible
			
		//! Output results FLOAT
		std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
		
		//! Output results DOUBLE
		std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
	}
	catch (std::exception &e)
	{
		// Catch any exceptions and mark all conversions as impossible
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
	}
}

/*
	Abbreviation	Full Form				Purpose
	isprint			is printable			Checks if a character is printable.
	isfinite		is finite				Checks if a number is finite.
	fixed			fixed-point notation	Outputs numbers in fixed-point notation.
	setprecision	set precision			Sets the number of digits after the decimal point.
	stod			string to double		Converts a string to a double.
	stof			string to float			Converts a string to a float.
	+inf			positive infinity		Represents positive infinity.
	-inf			negative infinity		Represents negative infinity.
	nan				not a number			Represents "Not a Number" (undefined).
	npos			no position				Indicates that a substring was not found.
*/