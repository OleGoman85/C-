/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 10:12:37 by ogoman            #+#    #+#             */
/*   Updated: 2024/10/10 12:28:21 by ogoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() : _name("default") {} // Default constructor initializing name to "default"

Zombie::~Zombie() // Destructor to announce the zombie's demise
{
	std::cout << _name << ": RrRrRrrrr...👋" << std::endl;
}

//zombie to announce itself
void Zombie::announce()
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

// Set the name of the zombie
void Zombie::setName(const std::string &name)
{
	_name = name;
}
