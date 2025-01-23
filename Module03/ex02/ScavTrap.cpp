/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 08:23:56 by ogoman            #+#    #+#             */
/*   Updated: 2024/11/13 08:44:56 by ogoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

// Default constructor
ScavTrap::ScavTrap() : ClapTrap("Default ScavTrap", false) // Pass false to suppress ClapTrap output
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap " << _name << " has been created by default constructor!" << std::endl;
}

// Constructor with name
ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name, false) // Pass false to suppress ClapTrap output
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "Energy points (100) 🪫" << std::endl;
	std::cout << "Health points (100) ❤️‍🔥" << std::endl;
	std::cout << "Attack Damage (20) 💣" << std::endl;
	std::cout << "ScavTrap " << _name << " has been created!" << std::endl;
}

// Copy constructor
ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	std::cout << _name << " has been copied to a new ScavTrap!" << std::endl;
}

// Destructor
ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << _name << " has been destroyed!" << std::endl;
}

//! Override attack method
void ScavTrap::attack(const std::string &target)
{
	if (_hitPoints > 0 && _energyPoints > 0)
	{
		std::cout << "ScavTrap " << _name << " attacks 💣" << target << ", causing " << _attackDamage << " points of damage! ❤️‍🩹" << std::endl;
		_energyPoints--;
	}
	else
	{
		std::cout << "ScavTrap " << _name << " can't attack because it has no hit points or energy points left!" << std::endl;
	}
}

// Special ability
void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << _name << " is now in Gatekeeper mode!" << std::endl;
}
