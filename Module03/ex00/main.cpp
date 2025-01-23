/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 12:52:52 by ogoman            #+#    #+#             */
/*   Updated: 2024/11/12 10:01:26 by ogoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap clap("Midas");

	clap.attack("Dragon 🐲");
	clap.takeDamage(3);
	clap.beRepaired(5);
	clap.attack("Wolf 🐺");
	clap.takeDamage(8);
	clap.beRepaired(2);

	return 0;
}
