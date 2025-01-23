/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:27:09 by ogoman            #+#    #+#             */
/*   Updated: 2024/11/26 08:05:28 by ogoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal 🦄")
{
	std::cout << "WrongAnimal created 🦄" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) : _type(other._type)
{
	std::cout << "WrongAnimal copied" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
	if (this != &other)
	{
		_type = other._type;
	}
	std::cout << "WrongAnimal assigned" << std::endl;
	return *this;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal 🦄 destroyed" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return _type;
}

void WrongAnimal::makeSound() const
{
	std::cout << "Some wrong animal sound: 🦄 frrrrp!" << std::endl;
}
