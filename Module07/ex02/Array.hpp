/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 08:13:52 by ogoman            #+#    #+#             */
/*   Updated: 2024/12/16 09:06:51 by ogoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception> // For std::exception
#include <cstddef>	 // For size_t
#include <stdexcept> // For std::out_of_range
#include <string>	 // For std::to_string (optional)

template <typename T>
class Array
{
	private:
		T *_array;	  // Pointer to the array
		size_t _size; // Number of elements in the array(n & x)

	public:
		// Default constructor: Creates an empty array
		Array() : _array(nullptr), _size(0) {}

		// Constructor with size parameter
		Array(unsigned int n) : _array(n > 0 ? new T[n]() : nullptr), _size(n) {}

		// Copy constructor
		Array(const Array &other) : _array(nullptr), _size(0)
		{
			*this = other;
		}

		// Destructor
		~Array()
		{
			delete[] _array;
		}

		// Assignment operator
		Array &operator=(const Array &other)
		{
			if (this != &other)
			{
				T *newArray = new T[other._size];
				for (size_t i = 0; i < other._size; ++i)
				{
					newArray[i] = other._array[i];
				}
				delete[] _array;
				_array = newArray;
				_size = other._size;
			}
			return *this;
		}

		// Subscript operator for accessing elements
		T &operator[](size_t index)
		{
			if (index >= _size)
			{
				throw std::out_of_range("Index " + std::to_string(index) + " out of bounds (size: " + std::to_string(_size) + ")");
			}
			return _array[index];
		}

		// Subscript operator for const objects
		const T &operator[](size_t index) const
		{
			if (index >= _size)
			{
				throw std::out_of_range("Index " + std::to_string(index) + " out of bounds (size: " + std::to_string(_size) + ")");
			}
			return _array[index];
		}

		// Size function: Returns the size of the array
		size_t size() const
		{
			return _size;
		}
};

#endif
