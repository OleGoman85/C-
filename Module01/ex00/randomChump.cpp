/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 12:44:04 by ogoman            #+#    #+#             */
/*   Updated: 2024/10/24 09:25:36 by ogoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void randomChump(std::string name)
{
	Zombie someZombie(name); // Create a Zombie object on the stack with the given name

	someZombie.announce(); // Create a Zombie object on the stack with the given name
}
