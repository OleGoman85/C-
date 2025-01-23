/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 10:12:53 by ogoman            #+#    #+#             */
/*   Updated: 2024/10/10 12:33:58 by ogoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



//! Memory Allocation: The new[] operator is used to allocate memory for an array of Zombie objects dynamically.
//! Constructor Invocation: If a default constructor is defined for the Zombie class, it is called for each object in the array.
//! Initial State: As a result, all zombies in the array will have a default name (like "default") unless specified otherwise in the constructor.

#include "Zombie.hpp"

Zombie *zombieHorde(int N, const std::string &name) // Create a horde of zombies
{
	if (N <= 0)
		return nullptr;

	Zombie *horde = new Zombie[N]; // Allocate an array of Zombie objects

	// Loop through the array to set the name for each zombie
	for (int i = 0; i < N; i++)
	{
		horde[i].setName(name);
	}

	return horde; // Return the pointer to the newly created horde
}
