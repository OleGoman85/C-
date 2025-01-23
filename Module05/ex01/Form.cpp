/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 09:28:03 by ogoman            #+#    #+#             */
/*   Updated: 2024/12/02 12:04:25 by ogoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute)
	: _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute), _isSigned(false) {}

Form::Form(const Form &other)
	: _name(other._name),
	  _gradeToSign(other._gradeToSign),
	  _gradeToExecute(other._gradeToExecute),
	  _isSigned(other._isSigned) {}

Form &Form::operator=(const Form &other)
{
	if (this != &other)
		_isSigned = other._isSigned;
	return *this;
}

Form::~Form() {}

const std::string &Form::getName() const { return _name; }
int Form::getGradeToSign() const { return _gradeToSign; }
int Form::getGradeToExecute() const { return _gradeToExecute; }
bool Form::isSigned() const { return _isSigned; }

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
		throw FormGradeTooLow();
	_isSigned = true;
}


const char *Form::FormGradeTooHigh::what() const noexcept
{
    return "Form grade is too high!";
}

const char *Form::FormGradeTooLow::what() const noexcept
{
    return "Form grade is too low!";
}

const char *Form::FormNotSigned::what() const noexcept
{
    return "Form is not signed!";
}

std::ostream &operator<<(std::ostream &outputStream, const Form &formObject)
{
	outputStream << "Form: " << formObject.getName() << "\n"
				 << "Grade to sign: " << formObject.getGradeToSign() << ", Grade to execute: " << formObject.getGradeToExecute() << "\n"
				 << "Signed: " << (formObject.isSigned() ? "Yes 👍" : "No 👎");

	if (formObject.isSigned())
	{
		outputStream << "\nStatus: ";
		if (formObject.getGradeToSign() <= formObject.getGradeToExecute())
			outputStream << "Signed and execute is possible.";
		else
			outputStream << "Signed but execute not possible (grade too low).";
	}
	return outputStream;
}
