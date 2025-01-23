/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 10:12:47 by ogoman            #+#    #+#             */
/*   Updated: 2024/10/24 09:39:41 by ogoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	int N = 3; // Number of zombies to create
	
	Zombie *horde = zombieHorde(N, "Zombie"); // Create a horde of zombies

	if (horde == nullptr) // Checking
	{
		std::cerr << "Failed to create zombie horde." << std::endl;
		return 1;
	}

	// Loop through each zombie in the horde and announce itself
	for (int i = 0; i < N; i++)
	{
		horde[i].announce();
	}

	delete[] horde; // Free the allocated memory for the zombie horde
	return 0;
}

/**
 * * This program defines a simple Zombie class and creates a horde of zombies. It includes functions to set the zombie's name and announce their presence.The zombieHorde function allocates an array of zombies and initializes their names. The main function creates a zombie horde, checks for allocation success, and has each zombie announce itself before cleaning up the allocated memory.
 */