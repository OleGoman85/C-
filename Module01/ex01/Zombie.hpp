/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 10:12:43 by ogoman            #+#    #+#             */
/*   Updated: 2024/10/10 12:28:31 by ogoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
	private:
		std::string _name;

	public:
		Zombie(); // Default constructor
		~Zombie(); // Destructor

		void announce(); // zombie to announce itself
		void setName(const std::string &name); // Function to set the zombie's name
};

Zombie *zombieHorde(int N, const std::string &name); // Function prototype for creating a horde of zombies

#endif
