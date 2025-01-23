/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 11:01:03 by ogoman            #+#    #+#             */
/*   Updated: 2024/11/26 08:06:35 by ogoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("Unknown Animal")
{
    std::cout << "Animal created 🦬" << std::endl;
}

Animal::Animal(const Animal &other) : _type(other._type)
{
    std::cout << "Animal copied" << std::endl;
}

Animal &Animal::operator=(const Animal &other)
{
    if (this != &other)
    {
        _type = other._type;
    }
    std::cout << "Animal assigned" << std::endl;
    return *this;
}

Animal::~Animal()
{
    std::cout << "Animal 🦬 destroyed" << std::endl;
}

std::string Animal::getType() const
{
    return _type;
}

void Animal::makeSound() const
{
    std::cout << "Some animal sound: 🦬 fgfdhrkkluuuu" << std::endl;
}
