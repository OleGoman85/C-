/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 12:53:02 by ogoman            #+#    #+#             */
/*   Updated: 2024/11/13 08:44:22 by ogoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// Default constructor
ClapTrap::ClapTrap() : _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap " << _name << " has been created by default constructor!" << std::endl;
}

// Constructor with name
ClapTrap::ClapTrap(const std::string &name, bool isBase = true) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	if (isBase) // Output only if it is directly ClapTrap
	{
		std::cout << "Energy points (10) 🪫" << std::endl;
		std::cout << "Health points (10) ❤️‍🔥" << std::endl;
		std::cout << "ClapTrap " << _name << " has been created!" << std::endl;
	}
}

// Copy constructor
ClapTrap::ClapTrap(const ClapTrap &other)
{
	*this = other; // Use assignment operator
	std::cout << "ClapTrap " << _name << " has been copied!" << std::endl;
}

// Destructor
ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << _name << " sustained damage incompatible with life! ☠️ " << std::endl;
	std::cout << "ClapTrap " << _name << " has been destroyed! 💔" << std::endl;
}

// Assignment operator
ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	if (this != &other)
	{
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	std::cout << "ClapTrap " << _name << " has been assigned!" << std::endl;
	return *this;
}

//! Attack
void ClapTrap::attack(const std::string &target)
{
	if (_hitPoints > 0 && _energyPoints > 0)
	{
		std::cout << "ClapTrap " << _name << " attacks 🧨" << target << ", causing " << _attackDamage << " points of damage! ❤️‍🩹" << std::endl;
		_energyPoints--;
	}
	else
	{
		std::cout << "ClapTrap " << _name << " can't attack because it has no hit points or energy points left!" << std::endl;
	}
}

// Take damage
void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints > 0)
	{
		_hitPoints = (_hitPoints > amount) ? (_hitPoints - amount) : 0;
		std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage.❤️‍🩹 Current hit points: 🪫" << _hitPoints << std::endl;
	}
	else
	{
		std::cout << "ClapTrap " << _name << " can't take more damage, it's already out of hit points!" << std::endl;
	}
}

// Be repaired
void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints > 0 && _energyPoints > 0)
	{
		_hitPoints += amount;
		_energyPoints--;
		std::cout << "ClapTrap " << _name << " repairs itself by " << amount << " points. Current hit points: 🪫" << _hitPoints << ", energy points left: " << _energyPoints << std::endl;
	}
	else
	{
		std::cout << "ClapTrap " << _name << " can't repair itself because it has no hit points or energy points left!" << std::endl;
	}
}
