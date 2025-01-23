/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:27:55 by ogoman            #+#    #+#             */
/*   Updated: 2024/12/16 09:11:54 by ogoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Whatever.hpp"
#include <iostream>
#include <string>
#include <cctype> // For std::isdigit

// ANSI codes for colors
#define RESET "\033[0m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"

// Function to check if a string contains only digits
bool isNumber(const std::string &str)
{
	for (char c : str)
	{
		if (!std::isdigit(c))
			return false;
	}
	return true;
}

int main(int argc, char **argv)
{
	// Check if the correct number of arguments is provided
	if (argc != 3)
	{
		std::cerr << "Usage: " << argv[0] << " <number1> <number2>" << std::endl;
		return 1;
	}

	std::string str_a = argv[1];
	std::string str_b = argv[2];

	// Check if both arguments are valid numbers
	if (!isNumber(str_a) || !isNumber(str_b))
	{
		std::cerr << "Input just numbers!" << std::endl;
		return 1;
	}

	std::cout << GREEN << "NUMBERS" << RESET << std::endl;

	// Convert strings to integers
	int a = std::stoi(str_a);
	int b = std::stoi(str_b);

	std::cout << "BEFORE SWAP\n"
			  << "a = " << a << ", b = " << b << std::endl;
	std::cout << "" << std::endl;

	::swap(a, b);
	std::cout << "AFTER SWAP" << std::endl;
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "" << std::endl;

	std::cout << "MIN & MAX" << std::endl;
	std::cout << "MIN (a vs b) = " << ::min(a, b) << std::endl;
	std::cout << "MAX (a vs b) = " << ::max(a, b) << std::endl;
	std::cout << "" << std::endl;
	

	std::cout << BLUE << "STRINGS" << RESET << std::endl;
	
	std::string c = "chaine1";
	std::string d = "chaine2";

	std::cout << "BEFORE SWAP\n"
			  << "c = " << c << ", d = " << d << std::endl;
	std::cout << "" << std::endl;

	// Swap the strings
	::swap(c, d);
	std::cout << "AFTER SWAP" << std::endl;
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "" << std::endl;

	std::cout << "MIN & MAX" << std::endl;
	std::cout << "MIN (c vs d) = " << ::min(c, d) << std::endl;
	std::cout << "MAX (c vs d) = " << ::max(c, d) << std::endl;

	return 0;
}

// int main( void ) {
//     int a = 2;
//     int b = 3;
//     ::swap( a, b );
//     std::cout << "a = " << a << ", b = " << b << std::endl;
//     std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
//     std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
//     std::string c = "chaine1";
//     std::string d = "chaine2";
//     ::swap(c, d);
//     std::cout << "c = " << c << ", d = " << d << std::endl;
//     std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
//     std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
//     return 0;
// }

// // same!

// // nnew;
// bool isNumber(const std::string& str)
// {
//     for (char c : str)
//     {
//         if (!std::isdigit(c))
//             return false;
//     }
//     return true;
// }

// // old
// bool isNumber(const std::string& str)
// {
//     for(int i = 0; i < str.size(); i++)
//     {
//         char c = str[i];
//         if(!std::isdigit(c))
//             return false;
//     }
//     return true;
// }