/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 07:20:16 by ogoman            #+#    #+#             */
/*   Updated: 2024/11/13 08:44:37 by ogoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ClapTrap clap("Midas 🤖", true);
	clap.attack("Dragon 🐲");
	clap.takeDamage(3);
	clap.beRepaired(5);

	std::cout << std::endl;

		// Test ScavTrap
	ScavTrap scav("Serena 👽");
	ClapTrap *robots_1 = &scav;

	robots_1->attack("Dragon 🐲");
	scav.takeDamage(10);
	scav.beRepaired(20);
	((ScavTrap *)robots_1)->guardGate();
	robots_1->attack("Wolf 🐺");
	scav.takeDamage(50);
	scav.beRepaired(10);
	scav.takeDamage(70);

	std::cout << std::endl;
	
		// Test FracTrap
	FragTrap frag("Optimus Prime 🦾");
	ClapTrap *robots_2 = &frag;

	robots_2->attack("Dragon 🐲");
	frag.takeDamage(20);
	frag.beRepaired(15);
	frag.highFivesGuys();
	// ((FragTrap *)robots_2) -> highFivesGuys();

	return 0;
}
