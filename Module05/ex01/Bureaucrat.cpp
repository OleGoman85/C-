/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 09:27:51 by ogoman            #+#    #+#             */
/*   Updated: 2024/11/20 12:42:10 by ogoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name), _grade(grade)
{
	if (grade < 1)
		throw BureaucratGradeTooHigh();
	if (grade > 150)
		throw BureaucratGradeTooLow();
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
		_grade = other._grade;
	return *this;
}

Bureaucrat::~Bureaucrat() {}

const std::string &Bureaucrat::getName() const { return _name; }
int Bureaucrat::getGrade() const { return _grade; }

void Bureaucrat::incrementGrade()
{
	if (_grade - 1 < 1)
		throw BureaucratGradeTooHigh();
	--_grade;
}

void Bureaucrat::decrementGrade()
{
	if (_grade + 1 > 150)
		throw BureaucratGradeTooLow();
	++_grade;
}

void Bureaucrat::signForm(Form &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << _name << " Signed 👍 " << form.getName() << std::endl;
	}
	catch (const std::exception &ex)
	{
		std::cerr << _name << " couldn’t sign 👎" << form.getName() << " because " << ex.what() << std::endl;
	}
}

const char *Bureaucrat::BureaucratGradeTooHigh::what() const noexcept
{
	return "Execution Grade is too high!";
}

const char *Bureaucrat::BureaucratGradeTooLow::what() const noexcept
{
	return "Execution Grade is too low!";
}

std::ostream &operator<<(std::ostream &outputStream, const Bureaucrat &bureaucrat)
{
	outputStream << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return outputStream;
}
