// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   main.cpp                                           :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2024/10/21 12:52:52 by ogoman            #+#    #+#             */
// /*   Updated: 2024/10/22 08:42:24 by ogoman           ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ClapTrap clap("Midas 🤖", true);
	clap.attack("Dragon 🐲");
	clap.takeDamage(3);
	clap.beRepaired(5);
	clap.attack("Wolf 🐺");
	clap.takeDamage(8);
	clap.beRepaired(2);

	std::cout << std::endl;

	// Test ScavTrap
	ScavTrap scav("Serena 👽");
	ClapTrap *robots = &scav;

	robots->attack("Dragon 🐲");
	scav.takeDamage(10);
	scav.beRepaired(20);
	((ScavTrap *)robots)->guardGate();
	robots->attack("Wolf 🐺");
	scav.takeDamage(50);
	scav.beRepaired(10);
	scav.takeDamage(70);

	return 0;
}