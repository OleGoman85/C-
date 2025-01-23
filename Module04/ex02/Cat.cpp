/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:51:31 by ogoman            #+#    #+#             */
/*   Updated: 2024/11/26 09:05:23 by ogoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

Cat::Cat() : Animal(), brain(new Brain())
{
	_type = "Cat🐱";
	std::cout << _type <<" constructed" << std::endl;
}

Cat::~Cat()
{
	delete brain;
	std::cout << "Cat🐱 destructed" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other), brain(new Brain(*other.brain))
{
	std::cout << "Cat🐱 copied" << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
	std::cout << "Cat🐱 assignment" << std::endl;
	if (this != &other)
	{
		delete brain;
		Animal::operator=(other);
		brain = new Brain(*other.brain);
	}
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "Meow!" << std::endl;
}

std::string Cat::getType() const {return _type;}

//* IDEAS *//

void Cat::addIdea(const std::string &idea) {
	brain->addIdea(idea);
}

void Cat::printIdeas() const {
	brain->printIdeas();
}