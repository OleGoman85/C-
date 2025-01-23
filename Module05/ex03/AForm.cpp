/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 07:29:34 by ogoman            #+#    #+#             */
/*   Updated: 2024/12/02 12:13:55 by ogoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"


AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute)
	: _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute), _isSigned(false) {}

AForm::AForm(const AForm &other)
	: _name(other._name), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute), _isSigned(other._isSigned) {}

AForm &AForm::operator=(const AForm &other)
{
	if (this != &other)
	{
		_isSigned = other._isSigned;
	}
	return *this;
}

AForm::~AForm() {}

// Getter
const std::string &AForm::getName() const
{
	return _name;
}

bool AForm::isSigned() const
{
	return _isSigned;
}

int AForm::getGradeToSign() const
{
	return _gradeToSign;
}

int AForm::getGradeToExecute() const
{
	return _gradeToExecute;
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_isSigned = true;
}

void AForm::execute(const Bureaucrat &executor) const
{
	if (!_isSigned)
		throw FormNotSignedException();
	if (executor.getGrade() > _gradeToExecute)
		throw GradeTooLowException();
	performAction();
}

const char *AForm::GradeTooHighException::what() const noexcept
{
	return "Grade is too high!";
}

const char *AForm::GradeTooLowException::what() const noexcept
{
	return "Grade is too low!";
}

const char *AForm::FormNotSignedException::what() const noexcept
{
	return "Form is not signed!";
}

// Оператор вывода
std::ostream &operator<<(std::ostream &os, const AForm &form)
{
	os << "Form: " << form.getName()
	   << "\nGrade to sign: " << form.getGradeToSign()
	   << "\nGrade to execute: " << form.getGradeToExecute()
	   << "\nSigned: " << (form.isSigned() ? "Yes" : "No");
	return os;
}
