/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 12:24:17 by ogoman            #+#    #+#             */
/*   Updated: 2024/12/02 11:59:20 by ogoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name), _grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs)
{
	if (this != &rhs)
	{
		_grade = rhs._grade;
	}
	return *this;
}

const std::string &Bureaucrat::getName() const { return _name; }
int Bureaucrat::getGrade() const { return _grade; }

void Bureaucrat::incrementGrade()
{
	if (_grade <= 1)
		throw GradeTooHighException();
	--_grade;
}

void Bureaucrat::decrementGrade()
{
	if (_grade >= 150)
		throw GradeTooLowException();
	++_grade;
}

// solve exception
const char *Bureaucrat::GradeTooHighException::what() const noexcept
{
	return "Grade is too high!";
}

const char *Bureaucrat::GradeTooLowException::what() const noexcept
{
	return "Grade is too low!";
}

// override
std::ostream &operator<<(std::ostream &outputStream, const Bureaucrat &bureaucrat)
{
	outputStream << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return outputStream;
}
