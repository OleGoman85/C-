/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 11:47:46 by ogoman            #+#    #+#             */
/*   Updated: 2024/10/24 09:37:02 by ogoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() : _name("default") {} // Default constructor initializes the name to "default"

Zombie::Zombie(std::string name) : _name(name) {}  // Constructor that sets the zombie's name

Zombie::~Zombie() // Destructor
{
	std::cout << _name << ": " << "RrRrRrrrr...👋" << std::endl;
}
void Zombie::setName(std::string name) {_name = name;} // Set the name of the Zombie

void Zombie::announce() // Announce the Zombie's presence
{
	std::cout << _name << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
}