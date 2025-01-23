/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 12:33:00 by ogoman            #+#    #+#             */
/*   Updated: 2024/11/26 09:04:06 by ogoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>

Animal::Animal() : _type("Unknown"){}

Animal::Animal(const Animal &obj) { (void)obj; }

Animal &Animal::operator=(const Animal &rhs)
{
	if (this != &rhs)
	{
		
	}
	return *this;
}

void Animal::makeSound() const {}

std::string Animal::getType() const
{
	return _type;
}
