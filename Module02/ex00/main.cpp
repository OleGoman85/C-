/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:18:19 by ogoman            #+#    #+#             */
/*   Updated: 2024/11/07 07:10:13 by ogoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main(void)
{
	Fixed a;	// Create an object using the default constructor
	Fixed b(a); // Create a new object by copying 'a' (calls the copy constructor)
	Fixed c;	// Create another object using the default constructor
	c = b;		// Assign the value of 'b' to 'c' (calls the assignment operator)


	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;

	return 0;
}
/**
//! Default constructor
ClassName(); 

//! Copy constructor
ClassName(const ClassName &other);

//! Assignment operator
ClassName &operator=(const ClassName &rhs);

//! Destructor
~ClassName();
*/