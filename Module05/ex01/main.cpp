/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 09:27:41 by ogoman            #+#    #+#             */
/*   Updated: 2024/12/02 12:05:12 by ogoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Form form1("Form1️⃣ ", 20, 10);
	Form form2("Form2️⃣ ", 120, 130);
	
	std::cout << "----------" << std::endl;
	std::cout << form1 << std::endl;
	std::cout << form2 << std::endl;
	std::cout << "\n-----ALICE-----" << std::endl;
	// Alice
	try
	{
		Bureaucrat alice("Alice 👻",5);
		std::cout << alice << std::endl;
		try
		{
			alice.incrementGrade();
			std::cout << alice << std::endl;
			alice.signForm(form1);
		}
		catch (const std::exception &exep)
		{
			std::cerr << alice.getName() << ": " << exep.what() << std::endl;
		}
	}

	catch (const std::exception &exep)
	{
		std::cerr << "📛 Error with Alice 👻: " << exep.what() << std::endl;
	}
	
	std::cout << "\n-----BOB-----" << std::endl;

	// Bob
	try
	{
		Bureaucrat bob("Bob 👽", 130);
		std::cout << bob << std::endl;


		try
		{
			bob.decrementGrade();
			std::cout << bob << std::endl;
			bob.signForm(form2);
		}
		catch (const std::exception &exep)
		{
			std::cerr << bob.getName() << ": " << exep.what() << std::endl;
		}
	}
	catch (const std::exception &exep)
	{
		std::cerr << "📛 Error with Bob 👽: " << exep.what() << std::endl;
	}
	
	std::cout << "\n-----RESULT-----\n" << std::endl;
	std::cout << form1 << std::endl;
	std::cout << "--------------" << std::endl;
	std::cout << form2 << std::endl;
	return 0;
}
