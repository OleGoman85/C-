/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:08:23 by ogoman            #+#    #+#             */
/*   Updated: 2024/12/09 07:46:50 by ogoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Serializer.hpp"

int main()
{
	// Create a Data object
	Data *originalData = new Data(42);
	std::cout << "Original Data value: " << originalData->_x << std::endl;
	

	// Serialize the pointer
	uintptr_t serialized = Serializer::serialize(originalData);
	std::cout << "Serialized value: " << serialized << std::endl;
	

	// Deserialize back to pointer
	Data *deserializedData = Serializer::deserialize(serialized);
	std::cout << "Deserialized Data value: " << deserializedData->_x << std::endl;
	

	// Check if the deserialized pointer equals the original pointer
	if (originalData == deserializedData)
	{
		std::cout << "Success: The deserialized pointer matches the original pointer!" << std::endl;
	}
	else
	{
		std::cout << "Failure: The deserialized pointer does not match the original pointer!" << std::endl;
	}

	// Clean up dynamically allocated memory
	delete originalData;

	return 0;
}

/*
UINTPTR_T is a type specifically designed to store memory addresses as integers, and it ensures that converting a pointer to an integer and back will be correct on any platform.


POINTER -> INT
SERIALIZE: Converts a pointer (Data*) into an integer of type uintptr_t. This process allows the pointer's address to be represented as a numeric value.


INT-> POINTER
DESERIALIZE: Converts an integer (uintptr_t) back into a pointer (Data*). This restores the original memory address from its numeric representation.
*/
