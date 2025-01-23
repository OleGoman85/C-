/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 11:01:22 by ogoman            #+#    #+#             */
/*   Updated: 2024/11/26 08:07:23 by ogoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



//   Cat::Cat(const Cat &other) : Animal(other)
//   └────┬────┘              └─────┬─────┘
//        │                         │
//  Конструктор                      Вызов конструктора
//  копирования                      копирования
//  для Cat                          для Animal

#include "Cat.hpp"

Cat::Cat() : Animal()
{
	_type = "Cat 🐱";
	std::cout << _type << " created" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other)
{
	std::cout << "Cat copied" << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
	if (this != &other)
	{
		Animal::operator=(other);
	}
	std::cout << "Cat assigned" << std::endl;
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat 🐱 destroyed" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "🐱 Meow!" << std::endl;
}
