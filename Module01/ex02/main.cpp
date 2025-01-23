/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:01:22 by ogoman            #+#    #+#             */
/*   Updated: 2024/10/10 12:36:19 by ogoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main()
{
	// Create a string variable initialized with the value "HI THIS IS BRAIN"
	std::string brain = "HI THIS IS BRAIN";

	// Create a pointer to the string variable
	std::string *stringPTR = &brain;

	// Create a reference to the string variable
	std::string &stringREF = brain;

	// Output the memory address of the string variable itself
	std::cout << "Memory address of variable brain: " << &brain << std::endl;

	// Output the memory address stored in stringPTR
	std::cout << "Memory address held by stringPTR: " << stringPTR << std::endl;

	// Output the memory address held by stringREF (same address as brain)
	std::cout << "Memory address held by stringREF: " << &stringREF << std::endl;

	std::cout << std::endl; // Empty line to separate output

	// Output the value of the string variable
	std::cout << "Value of variable brain: " << brain << std::endl;

	// Output the value pointed to by stringPTR
	std::cout << "Value pointed to by stringPTR: " << *stringPTR << std::endl;

	// Output the value referred to by stringREF
	std::cout << "Value referred to by stringREF: " << stringREF << std::endl;

	return 0;
}
