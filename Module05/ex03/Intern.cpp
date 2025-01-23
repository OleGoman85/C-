/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 07:39:45 by ogoman            #+#    #+#             */
/*   Updated: 2024/12/02 12:15:36 by ogoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include <iostream>
#include <functional>

Intern::Intern() {}
Intern::Intern(const Intern &other) { (void)other; }
Intern &Intern::operator=(const Intern &other) { (void)other; return *this; }
Intern::~Intern() {}

AForm* Intern::makeForm(const std::string &formName, const std::string &target)
{
    // List of known forms and functions to create them
    std::pair<std::string, std::function<AForm*(const std::string&)>> formPairs[] = {
        {"robotomy request", [](const std::string& target) { return new RobotomyRequestForm(target); }},
        {"shrubbery creation", [](const std::string& target) { return new ShrubberyCreationForm(target); }},
        {"presidential pardon", [](const std::string& target) { return new PresidentialPardonForm(target); }}
    };

    // Find a match for the form name
    for (size_t i = 0; i < sizeof(formPairs) / sizeof(formPairs[0]); ++i)
	{
        if (formPairs[i].first == formName)
		{
            std::cout << "Intern " << target << " creates " << formName << std::endl;
            return formPairs[i].second(target);
        }
    }

    // If form not found
    std::cerr << "Error: Form \"" << formName << "\" not found." << std::endl;
    return nullptr;
}

