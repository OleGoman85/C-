/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 07:39:26 by ogoman            #+#    #+#             */
/*   Updated: 2024/11/27 10:54:07 by ogoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <string>
#include <exception>

class Intern {
    public:
        Intern();
        Intern(const Intern &other);
        Intern &operator=(const Intern &other);
        ~Intern();

        AForm* makeForm(const std::string &formName, const std::string &target);
};

#endif
