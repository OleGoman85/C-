/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:50:35 by ogoman            #+#    #+#             */
/*   Updated: 2024/11/26 09:00:32 by ogoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal(), brain(new Brain())
{
	_type = "Dog🐶";
	std::cout << _type <<" constructed" << std::endl;
}

Dog::~Dog()
{
	delete brain;
	std::cout << "Dog🐶 destructed" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other), brain(new Brain(*other.brain))
{
	std::cout << "Dog🐶 copied" << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
	std::cout << "Dog🐶 assignment" << std::endl;
	if (this != &other)
	{
		delete brain;
		Animal::operator=(other);
		brain = new Brain(*other.brain);
	}
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "Woof!" << std::endl;
}

std::string Dog::getType() const {return _type;}

//* IDEAS *//

void Dog::addIdea(const std::string &idea) {
	brain->addIdea(idea);
}

void Dog::printIdeas() const {
	brain->printIdeas();
}
