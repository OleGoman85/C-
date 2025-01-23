/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 09:27:41 by ogoman            #+#    #+#             */
/*   Updated: 2024/12/03 11:51:24 by ogoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//!nuzno v itoge vse razkomentirovat

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp" 
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <ctime>

int main()
{
	std::srand(std::time(0)); // Initialize random seed for RobotomyRequestForm
	// ----------- ex03 ----------//
	Intern someRandomIntern; // Create an Intern object
	// --------------------------//
	
	// // Instantiate specific forms with targets
	// ShrubberyCreationForm form1("Garden");
	// RobotomyRequestForm form2("Target");
	// PresidentialPardonForm form3("Marvin");

	// // Print details of the created forms
	// std::cout << "----------" << std::endl;
	// std::cout << form1 << std::endl;
	// std::cout << form2 << std::endl;
	// std::cout << form3 << std::endl;

	// // Testing Alice
	// std::cout << "\n-----ALICE-----" << std::endl;
	// try
	// {
	// 	Bureaucrat alice("Alice 👻", 30); // Create Bureaucrat Alice with grade 30
	// 	std::cout << alice << std::endl;

	// 	try
	// 	{
	// 		alice.incrementGrade(); // Increment Alice's grade
	// 		std::cout << alice << std::endl;
	// 		alice.signForm(form1);	  // Sign ShrubberyCreationForm
	// 		alice.executeForm(form1); // Execute ShrubberyCreationForm
	// 	}
	// 	catch (const std::exception &exep)
	// 	{
	// 		std::cerr << alice.getName() << ": " << exep.what() << std::endl;
	// 	}
	// }
	// catch (const std::exception &exep)
	// {
	// 	std::cerr << "📛 Error with Alice 👻: " << exep.what() << std::endl;
	// }

	// // Testing Bob
	// std::cout << "\n-----BOB-----" << std::endl;
	// try
	// {
	// 	Bureaucrat bob("Bob 👽", 30); // Create Bureaucrat Bob with grade 30
	// 	std::cout << bob << std::endl;

	// 	try
	// 	{
	// 		bob.decrementGrade(); // Decrement Bob's grade
	// 		std::cout << bob << std::endl;
	// 		bob.signForm(form2);	// Sign RobotomyRequestForm
	// 		bob.executeForm(form2); // Execute RobotomyRequestForm
	// 	}
	// 	catch (const std::exception &exep)
	// 	{
	// 		std::cerr << bob.getName() << ": " << exep.what() << std::endl;
	// 	}
	// }
	// catch (const std::exception &exep)
	// {
	// 	std::cerr << "📛 Error with Bob 👽: " << exep.what() << std::endl;
	// }

	// // Testing Charlie
	// std::cout << "\n-----CHARLIE-----" << std::endl;
	// try
	// {
	// 	Bureaucrat charlie("Charlie 🛠️", 30); // Create Bureaucrat Charlie with grade 30
	// 	std::cout << charlie << std::endl;

	// 	try
	// 	{
	// 		charlie.incrementGrade(); // Increment Charlie's grade
	// 		std::cout << charlie << std::endl;
	// 		charlie.signForm(form3);	// Sign PresidentialPardonForm
	// 		charlie.executeForm(form3); // Execute PresidentialPardonForm
	// 	}
	// 	catch (const std::exception &exep)
	// 	{
	// 		std::cerr << charlie.getName() << ": " << exep.what() << std::endl;
	// 	}
	// }
	// catch (const std::exception &exep)
	// {
	// 	std::cerr << "📛 Error with Charlie 🛠️: " << exep.what() << std::endl;
	// }

	// // Testing Dave
	// std::cout << "\n-----DAVE-----" << std::endl;
	// try
	// {
	// 	Bureaucrat dave("Dave 🤖", 23); // Create Bureaucrat Dave with grade 23
	// 	std::cout << dave << std::endl;

	// 	try
	// 	{
	// 		dave.decrementGrade(); // Decrement Dave's grade
	// 		std::cout << dave << std::endl;
	// 		dave.signForm(form2);	 // Sign RobotomyRequestForm
	// 		dave.executeForm(form2); // Execute RobotomyRequestForm
	// 	}
	// 	catch (const std::exception &exep)
	// 	{
	// 		std::cerr << dave.getName() << ": " << exep.what() << std::endl;
	// 	}
	// }
	// catch (const std::exception &exep)
	// {
	// 	std::cerr << "📛 Error with Dave 🤖: " << exep.what() << std::endl;
	// }

	// // Print results of the forms
	// std::cout << "\n-----RESULT-----\n"
	// 		  << std::endl;
	// std::cout << form1 << std::endl;
	// std::cout << form2 << std::endl;
	// std::cout << form3 << std::endl;

	std::cout << " \n----------- Result ex03 ---------\n" << std::endl;
	
	// Example 1: Successfully creating a form
	AForm* form4 = someRandomIntern.makeForm("robotomy request", "Bender");
    if (form4)
	{
        std::cout << *form4 << std::endl;
        delete form4; // Free the dynamically allocated form
    }
	else
		std::cout << "No form created." << std::endl;
	
	std::cout << "\n---------------\n" << std::endl;
	
	// Example 2: Form not found
    AForm* form5 = someRandomIntern.makeForm("unknown form", "Target");
    if (form5)
	{
		std::cout << *form5 << std::endl;
		delete form5; // Free the dynamically allocated form
	}
	else
        std::cout << "No form created." << std::endl;
		
	return 0;
}
