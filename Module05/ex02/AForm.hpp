/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 09:27:55 by ogoman            #+#    #+#             */
/*   Updated: 2024/12/02 12:12:30 by ogoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <exception>
#include <iostream>

class Bureaucrat; // Forward declaration

class AForm
{
	private:
		const std::string _name;
		const int _gradeToSign;
		const int _gradeToExecute;
		bool _isSigned;

		virtual void performAction() const = 0;
		
	public:
		AForm(const std::string &name, int gradeToSign, int gradeToExecute);
		AForm(const AForm &other);
		AForm &operator=(const AForm &other);
		virtual ~AForm();

		const std::string &getName() const;
		bool isSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;

		void beSigned(const Bureaucrat &bureaucrat);

		void execute(const Bureaucrat &executor) const;

		class GradeTooHighException : public std::exception
		{
			const char *what() const noexcept override;
		};

		class GradeTooLowException : public std::exception
		{
			const char *what() const noexcept override;
		};

		class FormNotSignedException : public std::exception
		{
			const char *what() const noexcept override;
		};
};

std::ostream &operator<<(std::ostream &os, const AForm &form);

#endif
