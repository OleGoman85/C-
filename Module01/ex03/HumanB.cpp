/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 11:54:43 by ogoman            #+#    #+#             */
/*   Updated: 2024/10/09 11:55:07 by ogoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <iostream>

// Constructor
HumanB::HumanB(const std::string &name_B) : _name(name_B), _weapon(nullptr) {}

// Method to set weapon
void HumanB::setWeapon(Weapon &weapon_B) { _weapon = &weapon_B; }

// Attack method
void HumanB::attack() const
{
	if (_weapon)
	{
		std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
	}
	else
	{
		std::cout << _name << " has no weapon to attack." << std::endl;
	}
}
