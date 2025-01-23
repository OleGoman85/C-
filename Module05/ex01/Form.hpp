/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 09:27:55 by ogoman            #+#    #+#             */
/*   Updated: 2024/11/20 12:29:16 by ogoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const std::string _name;
	const int _gradeToSign;
	const int _gradeToExecute;
	bool _isSigned;

public:
	Form(const std::string &name, int gradeToSign, int gradeToExecute);
	Form(const Form &other);
	Form &operator=(const Form &other);
	~Form();

	const std::string &getName() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;
	bool isSigned() const;

	void beSigned(const Bureaucrat &bureaucrat);
	// void beExecuted(const Bureaucrat &executor) const;

class FormGradeTooHigh : public std::exception
{
    const char *what() const noexcept override;
};

class FormGradeTooLow : public std::exception
{
    const char *what() const noexcept override;
};

class FormNotSigned : public std::exception
{
    const char *what() const noexcept override;
};

};

std::ostream &operator<<(std::ostream &outputStream, const Form &formObject);

#endif
