/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 12:37:11 by ogoman            #+#    #+#             */
/*   Updated: 2024/10/24 09:54:11 by ogoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
	// Creating a weapon of type "Sword"
	Weapon sword("Sword");

	// Creating HumanA with a weapon
	HumanA alice("Alice", sword);
	alice.attack();

	// Creating HumanB without a weapon
	HumanB bob("Bob");
	bob.attack();

	// Equipping Bob with a weapon of type "Axe"
	Weapon axe("Axe");
	bob.setWeapon(axe);
	bob.attack();

	// Changing Alice's weapon type
	sword.setType("Gun");
	alice.attack();

	return 0;
}

//! Example from subject
// int main()
// {
// 	{
// 		Weapon club = Weapon("crude spiked club");
// 		HumanA bob("Bob", club);
// 		bob.attack();
// 		club.setType("some other type of club");
// 		bob.attack();
// 	}
// 	{
// 		Weapon club = Weapon("crude spiked club");
// 		HumanB jim("Jim");
// 		jim.setWeapon(club);
// 		jim.attack();
// 		club.setType("some other type of club");
// 		jim.attack();
// 	}
// 	return 0;
// }

/**
 * * This program defines three classes: Weapon, HumanA, and HumanB. The Weapon class manages a weapon's type and provides methods to get and set the weapon's type. The HumanA class represents a person who always has a weapon, passed as a reference in its constructor, and can perform an attack using that weapon. The HumanB class represents a person who may or may not have a weapon, allowing the weapon to be set later with a pointer, and can also attack if armed. Both HumanA and HumanB use their weapons to print a message during the attack.*/