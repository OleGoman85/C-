/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 08:13:34 by ogoman            #+#    #+#             */
/*   Updated: 2024/12/16 09:04:49 by ogoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

int main()
{

	std::cout << "<<Exercise Tip>>" << std::endl;
	int *a = new int();
	std::cout << "Default-initialized int: " << *a << std::endl;
	delete a;
	std::cout << "===========" << std::endl;
	try
	{
		// Test default constructor
		Array<int> emptyArray;
		std::cout << "Empty array size: " << emptyArray.size() << std::endl;

		// Test constructor with size
		unsigned int n = 5;
		unsigned int x = 15; //exeptation
		Array<int> intArray(n);
		std::cout << "intArray size: " << intArray.size() << std::endl;

		// Access and modify elements
		for (size_t i = 0; i < intArray.size(); ++i)
		{
			intArray[i] = static_cast<int>(i + 1);
		}

		std::cout << "intArray elements: ";
		for (size_t i = 0; i < intArray.size(); ++i)
		{
			std::cout << intArray[i] << " ";
		}
		std::cout << std::endl;

		// Test copy constructor
		Array<int> copiedArray = intArray;
		std::cout << "Copied array elements: ";
		for (size_t i = 0; i < copiedArray.size(); ++i)
		{
			std::cout << copiedArray[i] << " ";
		}
		std::cout << std::endl;

		// Modify original array and ensure copied array remains unchanged
		intArray[0] = 42;
		std::cout << "Modified intArray[0]: " << intArray[0] << std::endl;
		std::cout << "Copied array[0] remains: " << copiedArray[0] << std::endl;

		// Test with custom type
		Array<std::string> stringArray(3);
		stringArray[0] = "Hello";
		stringArray[1] = "World";
		stringArray[2] = "!";
		std::cout << "String array elements: ";
		for (size_t i = 0; i < stringArray.size(); ++i)
		{
			std::cout << stringArray[i] << " ";
		}
		std::cout << std::endl;

		// Test out-of-bounds access
		std::cout << "Attempting out-of-bounds access: " << std::endl;
		std::cout << intArray[x] << std::endl; // Should throw exception
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
