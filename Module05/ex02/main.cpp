/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 09:27:41 by ogoman            #+#    #+#             */
/*   Updated: 2024/12/04 12:16:27 by ogoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <ctime>

int main()
{
	std::srand(std::time(0));

	ShrubberyCreationForm form1("Garden");
	RobotomyRequestForm form2("Target");
	PresidentialPardonForm form3("Marvin");

	std::cout << "----------" << std::endl;
	std::cout << form1 << std::endl;
	std::cout << form2 << std::endl;
	std::cout << form3 << std::endl;


	std::cout << "\n-----ALICE-----" << std::endl;
	try
	{
		Bureaucrat alice("Alice 👻", 30);
		std::cout << alice << std::endl;

		try
		{
			alice.incrementGrade(); 
			std::cout << alice << std::endl;
			alice.signForm(form1);	  
			alice.executeForm(form1);
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
	try
	{
		Bureaucrat bob("Bob 👽", 30);
		std::cout << bob << std::endl;

		try
		{
			bob.decrementGrade(); 
			std::cout << bob << std::endl;
			bob.signForm(form2);	
			bob.executeForm(form2); 
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


	std::cout << "\n-----CHARLIE-----" << std::endl;
	try
	{
		Bureaucrat charlie("Charlie 🛠️", 30);
		std::cout << charlie << std::endl;

		try
		{
			charlie.incrementGrade(); 
			std::cout << charlie << std::endl;
			charlie.signForm(form3);	
			charlie.executeForm(form3); 
		}
		catch (const std::exception &exep)
		{
			std::cerr << charlie.getName() << ": " << exep.what() << std::endl;
		}
	}
	catch (const std::exception &exep)
	{
		std::cerr << "📛 Error with Charlie 🛠️: " << exep.what() << std::endl;
	}


	std::cout << "\n-----DAVE-----" << std::endl;
	try
	{
		Bureaucrat dave("Dave 🤖", 23);
		std::cout << dave << std::endl;

		try
		{
			dave.decrementGrade(); 
			std::cout << dave << std::endl;
			dave.signForm(form2);	
			dave.executeForm(form2);
		}
		catch (const std::exception &exep)
		{
			std::cerr << dave.getName() << ": " << exep.what() << std::endl;
		}
	}
	catch (const std::exception &exep)
	{
		std::cerr << "📛 Error with Dave 🤖: " << exep.what() << std::endl;
	}


	std::cout << "\n-----RESULT-----\n"
			  << std::endl;
	std::cout << form1 << std::endl;
	std::cout << form2 << std::endl;
	std::cout << form3 << std::endl;

	return 0;
}
