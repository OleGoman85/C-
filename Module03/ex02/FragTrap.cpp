/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 07:19:38 by ogoman            #+#    #+#             */
/*   Updated: 2024/11/13 08:44:30 by ogoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

// Default constructor
FragTrap::FragTrap() : ClapTrap("Default FragTrap", false)
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap " << _name << " has been created by default constructor!" << std::endl;
}

// Constructor with name
FragTrap::FragTrap(const std::string &name) : ClapTrap(name, false)
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "Energy points (100) 🪫" << std::endl;
	std::cout << "Health points (100) ❤️‍🔥" << std::endl;
	std::cout << "Attack Damage (30) 💥" << std::endl;
	std::cout << "FragTrap " << _name << " has been created!" << std::endl;
}

// Copy constructor
FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	std::cout << _name << " has been copied to a new FragTrap!" << std::endl;
}

// Destructor
FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << _name << " has been destroyed!" << std::endl;
}

//! Override attack method
void FragTrap::attack(const std::string &target)
{
	if (_hitPoints > 0 && _energyPoints > 0)
	{
		std::cout << "FragTrap " << _name << " attacks 💥" << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
		_energyPoints--;
	}
	else
	{
		std::cout << "FragTrap " << _name << " can't attack because it has no hit points or energy points left!" << std::endl;
	}
}

// Special ability
void FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << _name << " requests a positive high five! ✋" << std::endl;
}
