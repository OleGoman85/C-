/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 12:52:39 by ogoman            #+#    #+#             */
/*   Updated: 2024/10/23 07:21:11 by ogoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
private:
	std::string _name;
	unsigned int _hitPoints;
	unsigned int _energyPoints;
	unsigned int _attackDamage;

public:
	// Constructors
	ClapTrap();									// Default constructor
	ClapTrap(const std::string &name);			// Constructor with name
	ClapTrap(const ClapTrap &other);			// Copy constructor
	ClapTrap &operator=(const ClapTrap &other); // Assignment operator
	~ClapTrap();								// Destructor

	// Member functions
	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

#endif
