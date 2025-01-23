/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 10:40:26 by ogoman            #+#    #+#             */
/*   Updated: 2024/10/10 12:36:54 by ogoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <string>
#include "Weapon.hpp"

class HumanB
{
private:
	std::string _name;
	Weapon *_weapon; // Pointer to weapon

public:
	// Constructor
	HumanB(const std::string &name_B);

	// Method to set weapon
	void setWeapon(Weapon &weapon_B);

	// Attack method
	void attack() const;
};

#endif // HUMANB_HPP
