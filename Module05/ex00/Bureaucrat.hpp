/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 12:24:13 by ogoman            #+#    #+#             */
/*   Updated: 2024/11/18 09:05:27 by ogoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <stdexcept>

class Bureaucrat
{
private:
	const std::string _name;
	int _grade;

public:
	Bureaucrat(const std::string &name, int grade);
	~Bureaucrat();
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat &operator=(const Bureaucrat &rhs);

	const std::string &getName() const;
	int getGrade() const;

	void incrementGrade();
	void decrementGrade();

	//* Exception
	class GradeTooHighException : public std::exception
	{
		public:
			const char *what() const noexcept override;
	};

	class GradeTooLowException : public std::exception
	{
		public:
			const char *what() const noexcept override;
	};
};

std::ostream &operator<<(std::ostream &outputStream, const Bureaucrat &burObject);

#endif

//! std::ostream &operator<<(std::ostream &std::cout, const Bureaucrat &Alice); // "operator<<(std::cout, Alice)";

//! "noexcept" specifies that the what() method will not throw other exceptions when called.