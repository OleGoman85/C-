/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 07:19:57 by ogoman            #+#    #+#             */
/*   Updated: 2024/11/13 08:44:33 by ogoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap //! Inheritance (ClapTrap)
{
	public:
		FragTrap();						   // Default constructor
		FragTrap(const std::string &name); // Constructor with name
		FragTrap(const FragTrap &other);   // Copy constructor
		~FragTrap();					   // Destructor

		void attack(const std::string &target) override; //! Override attack method
		void highFivesGuys();							 // Special ability
};

#endif
