/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 07:13:35 by ogoman            #+#    #+#             */
/*   Updated: 2024/12/16 09:09:14 by ogoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

// Function to be called on each element of the array
template <typename T>
void print(const T &value)
{
	std::cout << value << "  ";
}

int main()
{
	// Test with an array of integers
	int intArray[] = {1, 2, 3, 4, 5, 6};
	size_t intArrayLength = sizeof(intArray) / sizeof(intArray[0]);

	std::cout << "Array of integers: ";
	iter(intArray, intArrayLength, print);
	std::cout << std::endl;


	// Test with an array of strings
	std::string strArray[] = {"Hello", "World", "C++", "Templates"};
	size_t strArrayLength = sizeof(strArray) / sizeof(strArray[0]);

	std::cout << "Array of strings: ";
	iter(strArray, strArrayLength, print);
	std::cout << std::endl;


	// Test with an array of floating point numbers
	float floatArray[] = {3.14, 1.59, 2.65};
	size_t floatArrayLength = sizeof(floatArray) / sizeof(floatArray[0]);

	std::cout << "Array of floats: ";
	iter(floatArray, floatArrayLength, print);
	std::cout << std::endl;

	return 0;
}

/*
TEMPLATE-tells the compiler that the following function or class is a template, meaning it can be used with different data types (int, float, std::string).

T - is the type, not a variable. T = type

TYPENAME - is used to specify the type parameter in the template.
*/