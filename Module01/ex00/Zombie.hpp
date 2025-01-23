/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 11:02:18 by ogoman            #+#    #+#             */
/*   Updated: 2024/10/24 09:25:50 by ogoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
#include <iostream>
 
class Zombie {
	private:
		std::string _name;
	
	public:
		Zombie(); // Default constructor
		Zombie(std::string name); // Constructor with name parameter
		~Zombie(); // Destructor
		
		void setName(std::string name); // Function to set the Zombie's name
		void announce(); // Function for the Zombie to announce itself
};

// Function prototypes for creating a Zombie on the heap and stack
Zombie *newZombie(std::string name);
void randomChump(std::string name);

#endif