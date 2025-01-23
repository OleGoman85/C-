/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:52:00 by ogoman            #+#    #+#             */
/*   Updated: 2024/11/26 09:12:25 by ogoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	Animal* a = new Animal(); //!test
	const Animal *j = new Dog();
	const Animal *i = new Cat();
	const Animal *l = new Cat();
	const Animal *r = new Dog();

	delete j;
	delete i;
	delete l;
	delete r;
	delete a;
}


//* sound / ideas *//

// #include <iostream>
// #include "Dog.hpp"
// #include "Cat.hpp"

// #define ARRAY_SIZE 4  // Defines the size of the animals array
// #define IDEA_MAX 99   // Maximum number of ideas that can be stored

// int main()
// {
// 	Animal *animals[ARRAY_SIZE];  // Array to store Animal pointers (alternating between Dog and Cat)

// 	// Create Dog and Cat objects in the animals array, alternating between them
// 	for (int i = 0; i < ARRAY_SIZE; ++i)
// 	{
// 		// Use static_cast to convert to Animal* type and alternate between Dog and Cat
// 		animals[i] = (i % 2 == 0) ? static_cast<Animal *>(new Dog()) : static_cast<Animal *>(new Cat());
// 	}

// 	int ideaIndex = 0; // Index to track the number of ideas added

// 	while (ideaIndex < IDEA_MAX && ideaIndex < ARRAY_SIZE)
// 	{
// 		// Loop through each Animal object in the array
// 		for (int i = 0; i < ARRAY_SIZE; ++i)
// 		{
// 			std::string userIdea;
// 			std::cout << "Enter idea #" << ideaIndex + 1 << ": ";
			
// 			std::getline(std::cin, userIdea);  // Get user input for the idea

// 			// Use dynamic_cast to determine if the object is a Dog or Cat, and add the idea accordingly
// 			Dog *dog = dynamic_cast<Dog *>(animals[i]);
// 			Cat *cat = dynamic_cast<Cat *>(animals[i]);

// 			if (dog)
// 			{
// 				dog->addIdea(userIdea); 
// 			}
// 			else if (cat)
// 			{
// 				cat->addIdea(userIdea);
// 			}

// 			ideaIndex++;
// 		}
// 	}

// 	ideaIndex = 1;

// 	// Display all ideas stored in each object's Brain
// 	for (int i = 0; i < ARRAY_SIZE; ++i)
// 	{
// 		// Use dynamic_cast to identify if the object is a Dog or Cat and display its ideas
// 		Dog *dog = dynamic_cast<Dog *>(animals[i]);
// 		Cat *cat = dynamic_cast<Cat *>(animals[i]);

// 		std::cout << animals[i]->getType() << " ideas:" << std::endl;
// 		if (dog)
// 		{
// 			std::cout << "Idea " << ideaIndex++ << ": ";
// 			dog->printIdeas(); 
// 			std::cout << animals[i]->getType() << " says: ";
// 			animals[i]->makeSound();
// 		}
// 		else if (cat)
// 		{
// 			std::cout << "Idea " << ideaIndex++ << ": ";
// 			cat->printIdeas(); 
// 			std::cout << animals[i]->getType() << " says: ";
// 			animals[i]->makeSound();
// 		}
// 	}

// 	// Deallocate memory for each Animal object in the array
// 	for (int i = 0; i < ARRAY_SIZE; ++i)
// 	{
// 		delete animals[i];
// 	}

// 	return 0;
// }
