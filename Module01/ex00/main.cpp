/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 12:12:02 by ogoman            #+#    #+#             */
/*   Updated: 2024/10/24 09:36:44 by ogoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	// Declare a pointer for a dynamically allocated Zombie
	Zombie *zom_heap;

	// Create a new Zombie on the heap and set its name
	zom_heap = newZombie("Zombie_heap");

	// Create a Zombie on the stack and announce itself
	randomChump("Zombie_stack");

	// Announce the heap-allocated Zombie
	zom_heap->announce();

	// Free the dynamically allocated Zombie to prevent memory leak
	delete zom_heap;
	return (0); // Indicate successful program termination
}

/**
 * *This program creates and manages instances of a Zombie class. It demonstrates dynamic memory allocation with heap-allocated zombies through the newZombie function and stack-allocated zombies via the randomChump function. Each zombie can announce itself when created, displaying its name and a characteristic phrase.
*/
