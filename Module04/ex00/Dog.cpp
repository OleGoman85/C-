/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 11:01:14 by ogoman            #+#    #+#             */
/*   Updated: 2024/11/26 08:07:59 by ogoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
	_type = "Dog 🐶";
	std::cout << _type << " created" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other)
{
	std::cout << "Dog copied" << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
		Animal::operator=(other);
	}
	std::cout << "Dog assigned" << std::endl;
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog 🐶 destroyed" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "🐶 Woof!" << std::endl;
}
