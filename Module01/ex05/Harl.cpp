/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 10:22:47 by ogoman            #+#    #+#             */
/*   Updated: 2024/10/24 09:55:30 by ogoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

void Harl::debug(void)
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info(void)
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void)
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string harl_complain)
{
	// Array of pointers to member functions of Harl class
	void (Harl::*all_complains_ptr[])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	// Array of complaint levels
	std::string arr_complains[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	
	int num_of_complains = sizeof(arr_complains) / sizeof(arr_complains[0]);

	for (int i = 0; i < num_of_complains; i++)
	{
		if (arr_complains[i] == harl_complain)
		{
			(this->*all_complains_ptr[i])();
			return;
		}
	}
	std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}

/*
!Pointers to member functions of a class
*return_type (ClassName::*pointer_name)(parameter_types) = &ClassName::FunctionName;

*return_type: the return type of the function.
*ClassName: the name of the class to which the function belongs.
*pointer_name: the name of the pointer.
*parameter_types: the types of the function parameters.
*&ClassName::FunctionName: the address of the member function of the class.

void (Harl::*all_complains_ptr[])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

void: The return type of all member functions. In this case, all functions debug, info, warning, and error return void.

(Harl::*)(): This syntax denotes a pointer to a member function of the Harl class that takes no parameters and returns void.

Harl:: Indicates that the member function belongs to the Harl class.
(): Indicates that the function takes no parameters.
all_complains_ptr[]: An array of pointers to member functions of the Harl class. The size of the array is determined by the initializer {...}.

= {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};: Initialization of the array of pointers to member functions. Each element of the array is the address of the corresponding member function of the Harl class.
*/
