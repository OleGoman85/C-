/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 09:27:46 by ogoman            #+#    #+#             */
/*   Updated: 2024/11/20 12:30:30 by ogoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include "Form.hpp"

class Form;

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

	void signForm(Form &form);

	class BureaucratGradeTooHigh : public std::exception
	{
		const char *what() const noexcept override;
	};

	class BureaucratGradeTooLow : public std::exception
	{
		const char *what() const noexcept override;
	};
};

std::ostream &operator<<(std::ostream &outputStream, const Bureaucrat &bureaucrat);

#endif
