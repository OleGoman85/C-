/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 12:24:06 by ogoman            #+#    #+#             */
/*   Updated: 2024/11/19 08:04:25 by ogoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	// Alice
	try
	{
		Bureaucrat Alice("Alice 👻", 7);
		std::cout << Alice << std::endl;

		try
		{
			Alice.incrementGrade();
			std::cout << Alice << std::endl;
		}
		catch (const std::exception &exep)
		{
			std::cerr << Alice.getName() << ": " << exep.what() << std::endl;
		}
	}
	catch (const std::exception &exep)
	{
		std::cerr << "Error with Alice 👻: " << exep.what() << std::endl;
	}

	// Bob
	try
	{
		Bureaucrat Bob("Bob 👽", 140);
		std::cout << Bob << std::endl;

		try
		{
			Bob.decrementGrade();
			std::cout << Bob << std::endl;
		}
		catch (const std::exception &exep)
		{
			std::cerr << Bob.getName() << ": " << exep.what() << std::endl;
		}
	}
	catch (const std::exception &exep)
	{
		std::cerr << "Error with Bob 👽: " << exep.what() << std::endl;
	}

	// Test exceptions
	// Charlie
	try
	{
		Bureaucrat Charlie("Charlie 🤖", 151); // Should throw GradeTooLowException
	}
	catch (const std::exception &exep)
	{
		std::cerr << "Charlie 🤖: " << exep.what() << std::endl;
	}

	// Diana
	try
	{
		Bureaucrat Diana("Diana 👹", 0); // Should throw GradeTooHighException
	}
	catch (const std::exception &exep)
	{
		std::cerr << "Diana 👹: " << exep.what() << std::endl;
	}

	return 0;
}
