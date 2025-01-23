/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 12:20:38 by ogoman            #+#    #+#             */
/*   Updated: 2024/10/24 09:25:41 by ogoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *newZombie(std::string name)
{
	Zombie *new_zombie = new Zombie; // Allocate a new Zombie object on the heap

	new_zombie->setName(name); // Set the name of the new Zombie

	return (new_zombie); // Return the pointer to the newly created Zombie
}
