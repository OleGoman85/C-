/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:12:22 by ogoman            #+#    #+#             */
/*   Updated: 2024/12/09 07:45:34 by ogoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::~Serializer() {}

// Serialize a pointer to uintptr_t
uintptr_t Serializer::serialize(Data *ptr)
{
	return reinterpret_cast<uintptr_t>(ptr); // Cast pointer to uintptr_t
}

// Deserialize a uintptr_t back to a pointer to Data
Data *Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data *>(raw); // Cast uintptr_t back to Data pointer
}

/*
REINTERPRET_CAST is a type cast operator in C++ used for performing unsafe conversions between different data types. It explicitly interprets the value of one type as another type.

STATIC_CAST: Not suitable because it cannot perform conversions between a pointer and an integer type.

DYNAMIC_CAST: Used only for checking and casting types within polymorphic class hierarchies.

CONST_CAST: Only modifies const or volatile qualifiers.
*/