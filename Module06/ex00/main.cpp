/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 07:38:43 by ogoman            #+#    #+#             */
/*   Updated: 2024/12/11 12:24:42 by ogoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

#include "ScalarConverter.hpp"

bool isValidNumber(const std::string &input)
{
	size_t i = 0;
	bool hasDot = false;
	bool hasF = false;

	// Check for optional sign
	if (input[i] == '+' || input[i] == '-')
	{
		i++;
	}
		

	// Ensure there is at least one digit or '.'
	if (!isdigit(input[i]) && input[i] != '.')
		return false;

	for (; i < input.length(); i++)
	{
		if (isdigit(input[i]))
			continue;

		if (input[i] == '.')
		{
			if (hasDot) // Multiple dots are not allowed
				return false;
			hasDot = true;
		}
		else if (input[i] == 'f' && i == input.length() - 1)
		{
			hasF = true; // 'f' is only allowed at the end
		}
		else
		{
			return false; // Invalid character
		}
	}

	return true;
}


int main(int ac, char **av)
{

	if (ac != 2)
	{
		std::cerr << "Usage: ./convert <literal>" << std::endl;
		return 1;
	}

	std::string input = av[1];

	// single CHAR
	if (input.length() == 1 && !isdigit(input[0]))
		ScalarConverter::convert(input);
		
	// special floating-point literals
	else if (input == "nan" || input == "+inf" || input == "-inf" ||
			 input == "nanf" || input == "+inff" || input == "-inff")
	{
		ScalarConverter::convert(input);
	}
	// VALID NUMBER
	else if (isValidNumber(input))
	{
		ScalarConverter::convert(input);
	}
	else
	{
		std::cerr << "Invalid literal provided!" << std::endl;
		return 1;
	}

	return 0;
}



/*
std::isprint
Checks if a character is printable (non-control character such as letters, digits, or punctuation marks).
std::cout << std::isprint('A'); // true (printable character)
std::cout << std::isprint('\n'); // false (control character)
*/

/*
std::isfinite
Checks if a number is finite (not +inf, -inf, or nan)
std::cout << std::isfinite(5.0); // true
std::cout << std::isfinite(1.0 / 0.0); // false (positive infinity)
*/

/*
std::fixed
Sets the output format for floating-point numbers to fixed-point notation.
std::cout << std::fixed << 3.14159; // 3.141590
*/

/*
std::setprecision
Specifies the number of digits to display after the decimal point for floating-point numbers.
std::cout << std::fixed << std::setprecision(2) << 3.14159; // 3.14
*/

/*
std::stod
Converts a string to a double.
double d = std::stod("3.14159");
std::cout << d; // 3.14159
*/

/*
std::stof
Converts a string to a float
float f = std::stof("3.14f");
std::cout << f; // 3.14
*/

/*
+inf (+inff for float):
Positive infinity. This occurs when a number is too large to be represented (e.g., the result of dividing by zero: 1.0 / 0.0).
*/

/*
-inf (-inff for float):
Negative infinity. Similar to +inf, but with a negative value (e.g., -1.0 / 0.0).
*/

/*
nan (nanf for float):
"Not a Number." This occurs in operations with undefined results (e.g., 0.0 / 0.0 or the square root of a negative number).
*/

/*
npos:
A special value from std::string::npos, used to indicate that a substring was not found.
It is the largest possible value of the size_t type (commonly represented as -1 in the context of strings).
*/

/*
std::numeric_limits<type>::min() Returns the smallest (most negative) finite value that can be represented by the given type.
std::numeric_limits<type>::max() Returns the largest finite value that can be represented by the given type.

#include <iostream>
#include <limits>

int main() {
	// Get the minimum and maximum values for char
	char c_min = std::numeric_limits<char>::min();
	char c_max = std::numeric_limits<char>::max();

	// Output the numeric values of c_min and c_max as integers
	std::cout << "char min: " << static_cast<int>(c_min) << std::endl;
	std::cout << "char max: " << static_cast<int>(c_max) << std::endl;

	/char min: -128
	/char max: 127

}

*/
