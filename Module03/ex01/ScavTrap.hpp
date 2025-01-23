/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 08:23:21 by ogoman            #+#    #+#             */
/*   Updated: 2024/11/13 08:44:13 by ogoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap //! Inheritance
{
	public:
		ScavTrap();						   // Default constructor
		ScavTrap(const std::string &name); // Constructor with name
		ScavTrap(const ScavTrap &other);   // Copy constructor
		~ScavTrap();					   // Destructor

		void attack(const std::string &target) override; //! Override attack method
		void guardGate();								 // Special ability
};

#endif
