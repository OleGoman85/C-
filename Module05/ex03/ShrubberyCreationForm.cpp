/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 07:37:21 by ogoman            #+#    #+#             */
/*   Updated: 2024/11/25 09:20:03 by ogoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <iostream>

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("Shrubbery Creation Form", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other), _target(other._target) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}

void ShrubberyCreationForm::performAction() const
{
	std::ofstream outfile(_target + "_shrubbery"); //!open for writing
	if (!outfile)
	{
		throw std::ios_base::failure("Failed to open file");
	}

	outfile << "     ccee88oo\n"	<< std::endl;
	outfile << "  C8O8O8Q8PoOb o8oo\n"	<< std::endl;
	outfile << " dOB69QO8PdUOpugoO9bD\n"	<< std::endl;
	outfile << "CgggbU8OU qOp qOdoUOdcb\n"	<< std::endl;
	outfile << "    6OuU  /p u gcoUodpP\n"	<< std::endl;
	outfile << "      \\\\//  /douUP\n"	<< std::endl;
	outfile << "        ||\n"	<< std::endl;
	outfile << "        ||\n"	<< std::endl;
	outfile << "        ||\n"	<< std::endl;
	outfile << "--------------------\n";
	outfile.close(); //!close
}
