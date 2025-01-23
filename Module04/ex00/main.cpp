/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 11:01:27 by ogoman            #+#    #+#             */
/*   Updated: 2024/11/27 07:19:13 by ogoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal *meta = new Animal();
	const Animal *j = new Dog();
	const Animal *i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete j;
	delete i;

	std::cout << "\n---------------WRONG CLASS-------------\n" << std::endl;

	const WrongAnimal *wrongAnimal = new WrongAnimal();
	const WrongAnimal *wrongCat = new WrongCat();
	const WrongCat *originSound = new WrongCat();

	wrongAnimal->makeSound();  // from WrongAnimal
	wrongCat->makeSound();     // from WrongAnimal (not virtual)
	
	std::cout << "Origin WrongCat sound: ";
	originSound->makeSound();  // from WrongCat

	std::cout << "WrongCat as WrongAnimal: ";
	static_cast<const WrongAnimal *>(wrongCat)->makeSound();  // makeSound from base class

	delete wrongAnimal;
	delete wrongCat;
	delete originSound;

	return 0;
}

/////////////////

// #include "Animal.hpp"
// #include "Dog.hpp"
// #include "Cat.hpp"

// int main()
// {
// 	Animal animal;
// 	Dog dog;
// 	Cat cat;

// 	// Creating base-type pointers to point to Dog and Cat objects
// 	Animal* ptr_Dog = &dog; //!
// 	Animal* ptr_Cat = &cat; //!

// 	// Printing the type of each animal
// 	std::cout << ptr_Cat->getType() << std::endl; // Should output "Cat"
// 	std::cout << ptr_Dog->getType() << std::endl; // Should output "Dog"

// 	// ((Cat *)ptr_Cat)->makeSound();
// 	// Calling makeSound() directly on the cat object (outputs "Meow!")
// 	cat.makeSound();

// 	// Using the base class (Animal) pointer to call makeSound() on the dog object (outputs "Woof!")
// 	ptr_Dog->makeSound();

// 	// Calling makeSound() for the animal object (outputs the base animal sound)
// 	animal.makeSound();
// 	return 0;
// }
