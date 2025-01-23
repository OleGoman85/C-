/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 09:27:46 by ogoman            #+#    #+#             */
/*   Updated: 2024/11/25 08:18:44 by ogoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"

class AForm; // Forward declaration

class Bureaucrat
{
private:
	const std::string _name;
	int _grade;

public:
	Bureaucrat(const std::string &name, int grade);
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat &operator=(const Bureaucrat &other);
	~Bureaucrat();

	const std::string &getName() const;
	int getGrade() const;

	void incrementGrade();
	void decrementGrade();

	void signForm(AForm &form) const;
	void executeForm(const AForm &form) const;

	class GradeTooHighException : public std::exception
	{
		const char *what() const noexcept override;
	};

	class GradeTooLowException : public std::exception
	{
		const char *what() const noexcept override;
	};
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif
