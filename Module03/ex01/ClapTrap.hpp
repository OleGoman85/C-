/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 12:52:39 by ogoman            #+#    #+#             */
/*   Updated: 2024/11/13 08:43:53 by ogoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
	protected:
		std::string _name;
		unsigned int _hitPoints;
		unsigned int _energyPoints;
		unsigned int _attackDamage;

	public:
		ClapTrap();										// Default constructor
		ClapTrap(const std::string &name, bool isBase); // Constructor with name & checking ClapTrap or ScavTrap
		ClapTrap(const ClapTrap &other);				// Copy constructor
		ClapTrap &operator=(const ClapTrap &other); // Assignment operator
		~ClapTrap();									// Destructor


		virtual void attack(const std::string &target); //! Make attack virtual
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif
